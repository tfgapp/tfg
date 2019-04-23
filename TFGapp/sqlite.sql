.cd C:/Users/Ulises/Desktop/tfg/TFGapp/TFGapp .open test.db

INSERT OR REPLACE INTO horarios(nombre,dia,sloot1,sloot2,sloot3,sloot4,sloot5,sloot6,sloot7) 
VALUES ('Profesor1 ProfellidoPrimero1',1,0, 1, 0, 0, 1, 1, 1);

INSERT INTO alumnos (nombre,apellido1,apellido2,correo,grado) 
VALUES ( 'Nombre1',Apellido11,Apellido2,Correo1gmail.com,1);

CREATE TABLE IF NOT EXISTS alumnos(
	nombre TEXT,
	apellido1 TEXT,
	apellido2 TEXT,
	correo TEXT PRIMARY KEY NOT NULL,
	grado INT
	FOREIGN KEY(grado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE NULL
);

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

CREATE TABLE IF NOT EXISTS grados(
	nombre TEXT PRIMARY KEY NOT NULL
);

CREATE TABLE IF NOT EXISTS especialidades(
	nombreProfesor TEXT PRIMARY KEY NOT NULL,
	nombreGrado TEXT,
	numeroMax INT,
	FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(nombreGrado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE NULL
);


CREATE TABLE IF NOT EXISTS persentacion(
	idPresentacion TEXT PRIMARY KEY NOT NULL,
	hora INT,
	dia INT,
	aula INT,
	slot INT,
	convocatoria INT,
	###  vector<Profesor *> tribunal, #Revisar por que puede ser turbio
);

CREATE TABLE IF NOT EXISTS TFG(
	titulo TEXT PRIMARY KEY NOT NULL,
	presentado TEXT,
	tutor TEXT,
	cotutor TEXT,
	presentacion TEXT,
	FOREIGN KEY(tutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(cotutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(presentacion) REFERENCES presentacion(idPresentacion)
	ON UPDATE CASCADE ON DELETE CASCADE,
);









