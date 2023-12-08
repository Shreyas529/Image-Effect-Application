package com.iiitb.imageEffectApplication.effectImplementations;
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
        return SepiaInterface.applySepia(image);
    
        
    }
}
