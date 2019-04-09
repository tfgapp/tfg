.cd C:/Users/Ulises/Desktop/tfg/TFGapp/TFGapp .open test.db

CREATE TABLE IF NOT EXISTS alumnos(
	nombre TEXT,
	apellido1 TEXT,
	apellido2 TEXT,
	correo TEXT PRIMARY KEY NOT NULL,
	grado INT
);

INSERT INTO alumnos (nombre,apellido1,apellido2,correo,grado) 
VALUES ( 'Nombre1',Apellido11,Apellido2,Correo1gmail.com,1);

CREATE TABLE IF NOT EXISTS profesores(
	nombreCompleto TEXT  PRIMARY KEY NOT NULL,
	doctor INT
);

CREATE TABLE IF NOT EXISTS horarios(
		nombre TEXT NOT NULL,
		dia INT,
		sloot1 INT,
		sloot2 INT,
		sloot3 INT,
		sloot4 INT,
		sloot5 INT,
		sloot6 INT,
		sloot7 INT,
		FOREIGN KEY(nombre) REFERENCES profesores(nombreCompleto)
		ON UPDATE CASCADE ON DELETE CASCADE
);