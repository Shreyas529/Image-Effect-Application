package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.GaussianBlurInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
public class GaussianEffect implements SingleValueParameterizableEffect{
    private float parameterValue;
    public GaussianEffect(){

    }
    public void setParameterValue(float parameterValue)
    {
        this.parameterValue=parameterValue;
    }
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        ExecuteLoggingService thread=new ExecuteLoggingService(loggingService, fileName,"Gaussion Blur Effect","Blur Radius = " + Float.toString(parameterValue));                                                      // modified image
        thread.start();
        while(thread.isAlive()){}
        return GaussianBlurInterface.applyGaussianBlur(image, parameterValue);
    }
    
}
