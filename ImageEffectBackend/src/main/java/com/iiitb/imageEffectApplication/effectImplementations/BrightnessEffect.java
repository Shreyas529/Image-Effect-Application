package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.BrightnessInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
public class BrightnessEffect implements SingleValueParameterizableEffect{
    private float parameter;
    public BrightnessEffect(){
    
    }
    @Override
    public void setParameterValue(float parameter)
    {
        this.parameter = parameter;
    }
    @Override
    public Pixel[][] apply(Pixel[][] image,String filename,LoggingService logging)
    {
        ExecuteLoggingService thread=new ExecuteLoggingService(logging, filename,"Brightness Effect","amount = " + Float.toString(parameter));                                                      // modified image
        thread.start();
        Pixel[][] result=BrightnessInterface.applyBrightness(image, parameter);
        while(thread.isAlive())
        {

        }
        return result;
    }
}
