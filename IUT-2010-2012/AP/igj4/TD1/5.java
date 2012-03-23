public class AppletMorpion extends Applet {
	public void init(){
		this.setLayout(new GrindLayout(1,1));
		this.add(new VueMorpion());
	}
}
