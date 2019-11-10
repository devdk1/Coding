package com.oops.constructor;

/**
 * Student
 */
public class Student extends Person {
    private String name;

    public Student() {
        System.out.println("Default constructor of chlid class called!");
    }

    public Student(int i, String str) {
        super(i);
        this.name = str;
        System.out.println("Parameterised constructor of chlid class called with name : "+str+" and age "+i);
    }

    public static void main(String args[]) {
        Student st = new Student();
        Student st1 = new Student(35, "Dev");
    }
}