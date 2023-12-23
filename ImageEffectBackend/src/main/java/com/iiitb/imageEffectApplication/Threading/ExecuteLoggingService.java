package com.iiitb.imageEffectApplication.Threading;
import com.iiitb.imageEffectApplication.service.*;
public class ExecuteLoggingService extends Thread{
    private LoggingService loggingService;
    private String filename;
    private String effectName;
    private String optionValues;

    public ExecuteLoggingService(LoggingService loggingService,String filename,String effectName,String optionValues)
    {
        this.loggingService=loggingService;
        this.filename=filename;
        this.effectName=effectName;
        this.optionValues=optionValues;

    }
    @Override
    public void run()
    {
       loggingService.addLog(filename,effectName,optionValues);
    }
}
