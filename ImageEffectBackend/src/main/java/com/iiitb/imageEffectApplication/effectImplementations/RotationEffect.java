package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.RotationInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class RotationEffect implements DiscreteEffect{
    private int value = 0;
    public RotationEffect(){

    }

    @Override
    public void selectOptionValue(String optionName,int value)
    {
        this.value = value;
    }

    @Override
    public Pixel[][] apply(Pixel[][] image,String filename,LoggingService logging)
    {
        // System.out.println("rotation?"+value);
        ExecuteLoggingService thread=new ExecuteLoggingService(logging, filename,"Rotation Effect","Rotation Value = " + Float.toString(value));                                                      // modified image
        thread.start();
        Pixel[][] result=RotationInterface.applyRotation(image, this.value);
        while(thread.isAlive()){}
        return result;
    }
}
