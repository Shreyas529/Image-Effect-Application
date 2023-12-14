package com.iiitb.imageEffectApplication.effectImplementations;
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
        return RotationInterface.applyRotation(image, this.value);
    }
}
