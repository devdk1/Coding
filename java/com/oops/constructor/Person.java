package com.oops.constructor;

class Person {
    private int age;

    public Person() {
        System.out.println("Default constructor of super class called!");
    }

    public Person(int i) {
        this.age = i;
        System.out.println("Parameterised constructor of super class called with age : "+i);
    }
}