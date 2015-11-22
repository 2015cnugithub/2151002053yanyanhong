package sphere;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

//�������������ı���ͼ����ʾ
public class TextController implements ActionListener{
    //�ÿ����������Ƶ�Sphere����
    private Sphere sphere;
    
    /** Creates a new instance of TextController */
    public TextController(Sphere sphere) {
        this.sphere=sphere;
    }
    
    public void actionPerformed(ActionEvent e) {
        JTextField t = (JTextField)e.getSource();
        double r = Double.parseDouble(t.getText());
        sphere.setRadius(r);
    }

}