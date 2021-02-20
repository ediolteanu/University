package com.oop_pub.exceptions.ex4;

import java.util.EnumSet;

public class ConsoleLogger extends LoggerBase {
    ConsoleLogger(EnumSet<LogLevel> enumSet) {
        super(enumSet);
    }

    @Override
    void writeMessage(String string) {
        System.out.println("[Console] " + string);
    }
}
