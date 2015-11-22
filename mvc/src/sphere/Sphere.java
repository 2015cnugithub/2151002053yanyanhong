package sphere;
import java.util.Observable;
public class Sphere extends Observable {
    private double radius;
    /** Creates a new instance of Sphere */
    public Sphere(int radius) {
        this.radius=radius;
    }
    /**
     * ���� radius �Ļ�ȡ������
     * @return ���� radius ��ֵ��
     */
    public double getRadius() {
        return radius;
    }
    /**
     * ���� radius �����÷�����
     * @param radius ���� radius ����ֵ��
     */
    public void setRadius(double radius) {
        this.radius=radius;
        this.setChanged();
        this.notifyObservers();
    }
    
    //����������
    public double volume() {
        return (double)4/(double)3*Math.PI*radius*radius*radius;
    }
    
    //������ı����
    public double surfaceArea() {
        return 4*Math.PI*radius*radius;
    }
    
}
