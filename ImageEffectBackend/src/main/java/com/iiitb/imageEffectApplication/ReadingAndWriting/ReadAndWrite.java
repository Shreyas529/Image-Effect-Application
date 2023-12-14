package com.iiitb.imageEffectApplication.ReadingAndWriting;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
public class ReadAndWrite implements Serializable{
    private static final String pathname=System.getProperty("user.dir")+"/src/main/java/com/iiitb/imageEffectApplication/ReadingAndWriting/object.dat";
    public static void WriteObject(Object obj){
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(pathname))) {
            outputStream.writeObject(obj);
        }
        catch(Exception ex)
        {
            
            ex.printStackTrace();
        }
    }
    public static Object ReadObject()
    {
        try(ObjectInputStream inputStream=new ObjectInputStream(new FileInputStream(pathname))){
            Object obj=inputStream.readObject();
            return obj;
        }
        catch(EOFException ex)
        {
            return null;
        }
        catch(Exception ex)
        {
            System.out.println(System.getProperty("user.dir"));
            ex.printStackTrace();
            return null;
        }
    }
}
