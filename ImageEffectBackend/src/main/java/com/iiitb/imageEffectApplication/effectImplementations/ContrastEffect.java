package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;

import com.iiitb.imageEffectApplication.libraryInterfaces.ContrastInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class ContrastEffect implements SingleValueParameterizableEffect{
    private float parameter;
    public ContrastEffect(){
    
    }
    @Override
    public void setParameterValue(float parameter)
    {
        this.parameter = parameter;
    }
    @Override
    public Pixel[][] apply(Pixel[][] image,String filename,LoggingService logging)
    {
        ExecuteLoggingService thread=new ExecuteLoggingService(logging, filename,"Contrast Effect","Contrast value = " + Float.toString(parameter));                                                      // modified image
        thread.start();
        while(thread.isAlive()){}
        return ContrastInterface.applyContrast(image, parameter);
    }
}
