package com.company.fourth;

import com.company.first.Task;
import com.company.second.Stack;
import com.company.third.Strategy;

public class RedoBackTaskRunner extends AbstractTaskRunner {
    public RedoBackTaskRunner(Strategy strategy) {
        super(strategy);
    }
    Stack stiva = new Stack();
    @Override
    protected void afterExecution(Task task) {
        stiva.push(task);
    }

    public void redo(){
        Task task;
        while(!stiva.isEmpty()){
            task = stiva.pop();
            task.execute();
        }
    }
}
