package com.iiitb.imageEffectApplication.effectImplementations;

import com.iiitb.imageEffectApplication.baseEffects.ParameterizableEffect;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.HueSaturationInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;

public class HueSaturationEffect implements ParameterizableEffect {
    private float hueValue=0;
    private float saturationValue=0;

    public HueSaturationEffect() {

    }

    @Override
    public void setParameter(String paramName, float value) {
        if (paramName.equals("hueValue")) {
            hueValue = value;
        }
        if (paramName.equals("saturationValue")) {
            saturationValue = value;
        }
    }
    @Override
    public Pixel[][] apply(Pixel[][] image, String filename, LoggingService logging) {
      
        return HueSaturationInterface.applyHueSaturation(image, saturationValue, hueValue);
    }

}
