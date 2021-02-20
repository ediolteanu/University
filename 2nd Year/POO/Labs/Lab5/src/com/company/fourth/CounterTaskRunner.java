package com.company.fourth;

import com.company.first.Task;
import com.company.third.Strategy;

public class CounterTaskRunner extends AbstractTaskRunner {
    static int contor = 0;

    public CounterTaskRunner(Strategy strategy) {
        super(strategy);
    }

    @Override
    protected void afterExecution(Task task) {
        contor++;
        System.out.println(contor);
    }
    public int getCounter(){
        return contor;
    }
}
