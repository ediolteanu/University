package com.company.third;

import com.company.second.Container;
import com.company.second.Queue;
import com.company.second.Stack;

public class ContainerFactory implements IFactory {
    public static final ContainerFactory INSTANCE = new ContainerFactory();

    private ContainerFactory() {
    }

    public Container createContainer(Strategy strategy) {
        if(strategy == Strategy.LIFO) return new Stack();
        return new Queue();
    }
}