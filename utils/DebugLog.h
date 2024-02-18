#pragma once
#ifdef BUILD_FOR_TEENSY
#include <Arduino.h>
#endif

#include <iostream>
#include <sstream>

#define DEBUG

#ifdef DEBUG
#define LOG(message) logDebug(std::ostringstream() << message)
#else
#define LOG(message) // Define as empty for release builds
#endif

// Forward declaration of logDebug function
void logDebug(const std::string &message);

// Log function for DEBUG builds
void logDebug(const std::ostringstream &oss)
{    
    logDebug(oss.str());
}

// Actual log function implementation
void logDebug(const std::string &message)
{
#ifdef BUILD_FOR_TEENSY
    Serial.println(message.c_str());
#endif
    // std::cout << message << std::endl;
}