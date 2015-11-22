package sphere;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

/**
 *
 * @author  Administrator
 */
public class SphereMain extends JFrame {
    
    /** Creates a new instance of SphereMain */
    public SphereMain() {
        super("mvc��ʾ����");
        setSize(400,200);
        Sphere sphere=new Sphere(50);//����ģ�Ͷ���
        TextView textView=new TextView();//�����ı���ͼ
        GraphicsView graphicsView=new GraphicsView();//����ͼ����ͼ
        //��Ӽ�����
        textView.getTextField().addActionListener(new TextController(sphere));
        graphicsView.addMouseMotionListener(new GraphicsController (sphere));
               //ģ������ͼ����
        sphere.addObserver(textView);
        sphere.addObserver(graphicsView);
        //����������
        Container c=getContentPane();
        c.setLayout(new GridLayout(1,2));
        c.add(textView);
        c.add(graphicsView);
        textView.update(sphere, null);
        graphicsView.update(sphere,null);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        new SphereMain().show();
    }
    
}
