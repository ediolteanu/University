package com.oop_pub.exceptions.ex4;

import java.util.EnumSet;

public abstract class LoggerBase {
    private LoggerBase next = null;
    private EnumSet<LogLevel> logLevels = null;
    LoggerBase(EnumSet<LogLevel> enumSet) {
        this.logLevels = enumSet;
    }

    public void setNext(LoggerBase next) {
        this.next = next;
    }

    abstract void writeMessage(String string);
    public void message(String string, LogLevel logLevel) {
        for (LogLevel logLevel1 : logLevels) {
            if (logLevel == logLevel1) {
                writeMessage(string);
            }
        }
        if (next != null) {
            next.message(string, logLevel);
        }
    }
}
