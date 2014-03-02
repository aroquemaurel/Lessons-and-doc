public enum Apprecation {
	EXCEPTIONNEL, TRESBIEN, BIEN, PASSABLE, MAUVAIS, TRESMAUVAIS
}

EnumSet<Apprecation> e1 = e.allOf(Apprecation.class);
EnumSet<Apprecation> e2 = e.range(Apprecation.EXCEPTIONNEL, Apprecation.BIEN);
EnumSet<Apprecation> e3 = e.complementOf(e2);
EnumSet<Apprecation> e34= e.of(Apprecation.EXCEPTIONNEL);

