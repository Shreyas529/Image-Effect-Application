package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.GrayscaleInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
public class GrayScaleEffect implements PhotoEffect{
    public GrayScaleEffect()
    {

    }
    @Override
    public Pixel[][] apply(Pixel[][] image , String filename , LoggingService logging)
    {
        // System.out.println("In grayscaleeffect.jav in effect implementation");
        ExecuteLoggingService thread=new ExecuteLoggingService(logging, filename,"Grayscale Effect","None");                                                      // modified image
        thread.start();
        Pixel[][] result=GrayscaleInterface.applyGrayscale(image);
        while(thread.isAlive()){}
        return result;
    }
    
}
