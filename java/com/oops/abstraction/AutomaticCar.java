package com.oops.abstraction;

public class AutomaticCar implements Car{
    private String carType = "Automatic";

    @Override
    public void turnOnCar() {
        System.out.println("turn on the Automatic car");
    }

    @Override
    public void turnOffCar() {
        System.out.println("turn off the Automatic car");
    }

    @Override
    public String getCarType() {
        return this.carType;
    }
}