package com.iiitb.imageEffectApplication.service;
import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import com.iiitb.imageEffectApplication.ReadingAndWriting.ReadAndWrite;


@Service
public class LoggingService implements Serializable{
    private List<LogModel> logs=null;
    public void addLog(String fileName, String effectName, String optionValues) {
        if(logs==null)
        {
            logs=new ArrayList<LogModel>();
        }
        
        String timeStamp = new SimpleDateFormat("yyyy.MM.dd.HH.mm.ss").format(new java.util.Date());
        
        LogModel log=new LogModel(timeStamp,fileName,effectName,optionValues);
        logs.add(log);
        ReadAndWrite.WriteObject(logs);
        
        return;
    }

    public List<LogModel> getAllLogs() {
        
        if(logs==null)
        {
            logs=(List<LogModel>)ReadAndWrite.ReadObject();
            
        }
        
        return logs;
    }

    public List<LogModel> getLogsByEffect(String effectName) {

        List<LogModel> effects=new ArrayList<LogModel>();
        for(LogModel log:logs)
        {
            if(log.getEffectName().equalsIgnoreCase(effectName))
            {
                effects.add(log);
            }
        }
        return effects;
    }

    public void clearLogs() {
        logs.clear();
        ReadAndWrite.WriteObject(logs);
    }

    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {
        return new ArrayList<LogModel>();
    }
}
