package sphere;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
//������������ͼ����ͼ����ʾ
public class GraphicsController implements MouseMotionListener{
	    private Sphere sphere;
        /** Creates a new instance of Controller */
   public GraphicsController(Sphere sphere) {
        this.sphere=sphere;
    }
	public void mouseDragged(MouseEvent e) {
		if(e.getX()>0)
			sphere.setRadius(e.getX());
		else sphere.setRadius(0);
		
}
	public void mouseMoved(MouseEvent e) {
			}

}
