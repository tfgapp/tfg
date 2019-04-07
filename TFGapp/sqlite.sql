.cd C:/Users/Ulises/Desktop/TFGapp/TFGapp .open test.db

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
	nombre TEXT,
	apellido1 TEXT,
	apellido2 TEXT,
	correo TEXT PRIMARY KEY NOT NULL,
	doctor INT
);