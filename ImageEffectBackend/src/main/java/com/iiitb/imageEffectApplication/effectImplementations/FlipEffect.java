package com.iiitb.imageEffectApplication.effectImplementations;
import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
//import com.iiitb.imageEffectApplication.baseEffects.requiredEffect;
// import com.iiitb.imageEffectApplication.baseEffects.DiscreteEffect;
import com.iiitb.imageEffectApplication.libraryInterfaces.FlipInterface;
// import com.iiitb.imageEffectApplication.libraryInterfaces.FlipInterface;
import com.iiitb.imageEffectApplication.libraryInterfaces.Pixel;
import com.iiitb.imageEffectApplication.service.LoggingService;
public class FlipEffect implements DiscreteEffect{
    private int horizontalFlipValue=0,verticalFlipValue=0;
    public FlipEffect(){

    }

    @Override
    public void selectOptionValue(String optionName,int value)
    {
        if(optionName.equals("verticalFlipValue"))
        {
            // System.out.println("Changing the value of vertical flip in FlipEffect.java");
            this.verticalFlipValue=value;
        }
        else if(optionName.equals("horizontalFlipValue"))
        {
            // System.out.println("Changing the value of horizontal flip in FlipEffect.java");
            this.horizontalFlipValue=value;
        }
    }

    @Override
    public Pixel[][] apply(Pixel[][] image,String filename,LoggingService logging)
    {
        // System.out.println("Calling the apply flip in FlipEffect.java");
        return FlipInterface.applyFlip(image, horizontalFlipValue, verticalFlipValue);
    }

    
}
