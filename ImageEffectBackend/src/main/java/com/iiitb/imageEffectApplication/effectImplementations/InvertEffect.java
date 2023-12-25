package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.InvertInterface;
import com.iiitb.imageEffectApplication.service.LoggingService;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
public class InvertEffect implements PhotoEffect{
    public InvertEffect(){

    }
    @Override
        public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){
        ExecuteLoggingService thread=new ExecuteLoggingService(loggingService, fileName,"Invert Effect","None");                                                      // modified image
        thread.start();
        while(thread.isAlive()){}
        return InvertInterface.applyInvert(image);
    }
    
}
