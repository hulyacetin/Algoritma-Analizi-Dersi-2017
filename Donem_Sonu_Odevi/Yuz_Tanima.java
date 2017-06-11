package yuz_tanima;

import java.io.File;
import java.io.FilenameFilter;
import java.nio.IntBuffer;

import static org.bytedeco.javacpp.opencv_core.CV_32SC1;
import org.bytedeco.javacpp.opencv_face.*;
import org.bytedeco.javacpp.opencv_core.Mat;
import org.bytedeco.javacpp.opencv_core.MatVector;
import static org.bytedeco.javacpp.opencv_face.createEigenFaceRecognizer;
import static org.bytedeco.javacpp.opencv_highgui.cvWaitKey;
import static org.bytedeco.javacpp.opencv_imgcodecs.CV_LOAD_IMAGE_GRAYSCALE;
import static org.bytedeco.javacpp.opencv_imgcodecs.imread;
import org.bytedeco.javacv.CanvasFrame;
import org.bytedeco.javacv.OpenCVFrameConverter;

/**
 *
 * @author erts
 */
 
public class Yuz_Tanima {


    /**
     * @param args the command line arguments
     */
    

    static void display(Mat image, String caption, int loc_x, int loc_y ,int defaultCloseOperationCode) {
        final CanvasFrame canvas = new CanvasFrame(caption, 1.0);
        
        canvas.setDefaultCloseOperation(defaultCloseOperationCode);
        
        // Görüntü OpenCV Mat formatından Java Buffered image formatına dönüştürülüyor
        final OpenCVFrameConverter converter = new OpenCVFrameConverter.ToMat();
        // Görüntü gösteriliyor
        canvas.showImage(converter.convert(image));
        canvas.setLocation(loc_x, loc_y);
    }
 
    
    public static void main(String[] args) throws InterruptedException {
      
        //Eğitim için kullanacağım veri setinin dizini
        String trainingDir = "C:\\Users\\erts\\Desktop\\ornek_res_opencv\\egitim";
        //Eşleştirme için kullanacağım diğer yüz
        Mat testImage = imread("C:\\Users\\erts\\Desktop\\ornek_res_opencv\\eslestirme\\1-ertugrul_1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
        
        File root = new File(trainingDir);

        FilenameFilter imgFilter = new FilenameFilter() {
            public boolean accept(File dir, String name) {
                name = name.toLowerCase();
                return name.endsWith(".jpg") || name.endsWith(".pgm") || name.endsWith(".png");
            }
        };

        File[] imageFiles = root.listFiles(imgFilter);

        MatVector images = new MatVector(imageFiles.length);

        Mat labels = new Mat(imageFiles.length, 1, CV_32SC1);
        IntBuffer labelsBuf = labels.createBuffer();

        int counter = 0;

        for (File image : imageFiles) {
            Mat img = imread(image.getAbsolutePath(), CV_LOAD_IMAGE_GRAYSCALE);
            
      
            display(img, "Eğitim İçin Kullanılan Görüntü",675, 20, 2);
            
            Thread.sleep(1000);
       
            int label = Integer.parseInt(image.getName().split("\\-")[0]);
            System.out.println("Eğitilen Yüz: "+label);
            images.put(counter, img);

            labelsBuf.put(counter, label);

            counter++;
        }
        
        FaceRecognizer faceRecognizer = createEigenFaceRecognizer();
        

        faceRecognizer.train(images, labels);
        
        display(testImage, "Tanınacak Yüz Görüntüsü",25, 20, 3);
        
        int predictedLabel = faceRecognizer.predict_label(testImage);
        System.out.println("Bulunan Yüz ID: " + predictedLabel);
        cvWaitKey(0);
    }
    
}
