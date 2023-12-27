package com.iiitb.imageEffectApplication.libraryInterfaces;

public class DominantInterface {
    static {
        String libraryPath = "DominantLib";
        LoadNativeLibrary.loadNativeLibrary(libraryPath);
    }
    public static native Pixel[][] applyDominant(Pixel[][] image);
}

