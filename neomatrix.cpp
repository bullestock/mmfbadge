/*
 * Neomatrix - Copyright (C) 2017 Lars Christensen
 * MIT Licensed
 *
 * Main display code
 */

#include <FastLED.h>

#include "common.hpp"
#include "display.hpp"
#include "program.hpp"

Program* current = nullptr;
uint32_t startTime = 0;
ProgramFactory* currentFactory = nullptr;

extern void show();

void neomatrix_init()
{
    currentFactory = ProgramFactory::first;
    current = currentFactory->launch();
    Serial.printf("Launched %s\n", currentFactory->name);
    startTime = millis();
}

#define RUNTIME 60000

void program_loop()
{
    uint32_t now = millis();
    uint32_t prgTime = now - startTime;
    if (prgTime >= RUNTIME)
    {
        clear_all();
        show();
        delete current;

        currentFactory = currentFactory->next;
        if (!currentFactory)
            currentFactory = ProgramFactory::first;
        current = currentFactory->launch();
        
        Serial.printf("Launched %s\n", currentFactory->name);
        startTime = now;
    }
}

void neomatrix_run()
{
    program_loop();
    if (current->run())
        show();
}

void neomatrix_change_program(const char* name)
{
    auto p = ProgramFactory::get(name);
    if (!p)
    {
        Serial.println("Not found");
        return;
    }
    current = p->launch();
    clear_all();
}
