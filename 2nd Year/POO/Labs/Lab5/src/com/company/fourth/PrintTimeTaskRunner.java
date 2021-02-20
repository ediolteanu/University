package com.company.fourth;

import com.company.first.Task;
import com.company.third.Strategy;

import java.util.Calendar;

public class PrintTimeTaskRunner extends AbstractTaskRunner {
    public PrintTimeTaskRunner(Strategy strategy) {
        super(strategy);
    }

    @Override
    protected void afterExecution(Task task) {
        Calendar time = Calendar.getInstance();
        System.out.println(time.getTime());
    }
}
