create table TA (
	A1 number,
	A2 varchar2(30),
	A3 varchar2(30),
	A4 varchar2(100),
	A5 varchar2(10),
	A6 date,
	A7 varchar2(8),
	A8 number(7),
	A9 varchar2(1),
	A10 number,
	constraint pk_TA primary key(A1),
	constraint fk_TA_TB foreign key(A10) references(TB)
);

create table TB (
	A11 number,
	A12 varchar2(30),
	A13 varchar2(100),
	A14 varchar2(10),
	constraint pk_TB primary key(A11)
);

create table TC (
	A15 number,
	A16 varchar2(30),
	A17 date,
	A18 date,
	A19 date,
	A20 date,
	A21 varchar2(8),
	A22 varchar2(100),
	A23 number,
	A24 number,
	A25 number,
	A26 number,
	constraint pk_TC primary key(A15),
	constraint fk_TC_TB foreign key(A26) references(TB)
);

create table TD (
	A27 varchar2,
	constraint pk_TD primary key(A27)
);

create table TE (
	A28 varchar2,
	constraint pk_TE primary key(A28)
);

create table TF(
	A29 number,
	A30 date,
	A31 date,
	A32 number,
	A33 varchar2(2),
	A34 varchar(12),
	constraint pk_TF primary key(A29),
	constraint fk_TF_TE foreign key(A32) references(TE),
	constraint fk_TF_TC foreign key(A33) references(TC),
	constraint fk_TF_TD foreign key(A34) references(TD)
);

create table TG(
	A35 number,
	A36 varchar2(2),
	A37 varchar2(12)
	constraint pk_TG primary key(A35,A36,A37),
	constraint fk_TG_TA foreign key(A35) references(TA),
	constraint fk_TG_TE foreign key(A36) references(TE),
	constraint fk_TG_TD foreign key(A37) references(TD)
);

