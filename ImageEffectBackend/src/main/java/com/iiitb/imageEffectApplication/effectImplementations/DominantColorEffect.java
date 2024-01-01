package com.iiitb.imageEffectApplication.effectImplementations;

import com.iiitb.imageEffectApplication.Threading.ExecuteLoggingService;
import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.DominantInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class DominantColorEffect implements PhotoEffect {

    public DominantColorEffect() {

    }

    @Override
    public Pixel[][] apply(Pixel[][] image, String filename, LoggingService logging) {
        ExecuteLoggingService thread = new ExecuteLoggingService(logging, filename, "Dominant Color Effect", "None");
        thread.start();
        Pixel[][] result=DominantInterface.applyDominantColor(image);
        while (thread.isAlive()) {
        }
        return result;
    }

}
