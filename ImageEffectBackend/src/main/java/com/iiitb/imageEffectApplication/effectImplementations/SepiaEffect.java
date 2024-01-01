package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.SepiaInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;

public class SepiaEffect implements PhotoEffect{
    public SepiaEffect()
    {

    }
    @Override
    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        ExecuteLoggingService thread=new ExecuteLoggingService(loggingService, fileName,"Sepia Effect","None");                                                      // modified image
        thread.start();
        Pixel[][] result=SepiaInterface.applySepia(image);;
        while(thread.isAlive()){}
        return result;
    
        
    }
}
