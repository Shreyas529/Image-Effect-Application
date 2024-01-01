package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.SharpenInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;
public class SharpenEffect implements SingleValueParameterizableEffect{
    private float parameterValue;
    public SharpenEffect(){

    }
    public void setParameterValue(float parameterValue)
    {
        this.parameterValue=parameterValue;
    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        ExecuteLoggingService thread=new ExecuteLoggingService(loggingService, fileName,"Sharpen Effect","Sharpen value = " + Float.toString(parameterValue));                                                      // modified image
        thread.start();
        Pixel[][] result=SharpenInterface.applySharpen(image, parameterValue);
        while(thread.isAlive()){}
        return result;
    }   
}