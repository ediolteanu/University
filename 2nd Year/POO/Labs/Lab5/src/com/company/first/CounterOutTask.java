package com.company.first;

public class CounterOutTask implements Task {
    static int contor = 0;
    @Override
    public void execute() {
        contor++;
        System.out.println(contor);
    }
}
