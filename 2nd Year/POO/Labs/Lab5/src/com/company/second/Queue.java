package com.company.second;

import com.company.first.Task;

import java.util.ArrayList;

public class Queue implements Container {
    ArrayList<Task> list = new ArrayList<Task>();
    @Override
    public Task pop() {
        if(!list.isEmpty()) {
            Task item = list.get(0);
            list.remove(0);
            return item;
        }
        else return null;
    }

    @Override
    public void push(Task task) {
        list.add(task);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void transferFrom(Container container) {
        Task element;
        while(!container.isEmpty()) {
            element = container.pop();
            push(element);
        }
    }
}
