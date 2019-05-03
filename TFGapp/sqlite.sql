.cd C:/Users/Ulises/Desktop/tfg/TFGapp/TFGapp .open test.db

CREATE TABLE IF NOT EXISTS alumnos(
	nombre TEXT,
	apellidos TEXT,
	ID TEXT PRIMARY KEY NOT NULL,
	grado TEXT,
	FOREIGN KEY(grado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE SET NULL
);

CREATE TABLE IF NOT EXISTS profesores(
	nombreCompleto TEXT PRIMARY KEY,
	doctor INT
);

CREATE TABLE IF NOT EXISTS grados(
	nombre TEXT PRIMARY KEY
);

--Tabla que conecta profesores y grados 
CREATE TABLE IF NOT EXISTS especialidades(
	nombreProfesor TEXT,
	nombreGrado TEXT,
	numeroMax INT,
	FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(nombreGrado) REFERENCES grados(nombre)
	ON UPDATE CASCADE ON DELETE SET NULL,
	PRIMARY KEY (nombreProfesor, nombreGrado)
);

CREATE TABLE IF NOT EXISTS disponibilidad(
	nombreProfesor TEXT NOT NULL,
	dia INT,
	slot1 INT,
	slot2 INT,
	slot3 INT,
	slot4 INT,
	slot5 INT,
	slot6 INT,
	slot7 INT,
	PRIMARY KEY(nombreProfesor, dia),
	FOREIGN KEY(nombreProfesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS tfg(
	titulo TEXT PRIMARY KEY,
	presentado INT,
	tutor TEXT,
	cotutor TEXT,
	alumno TEXT,
	FOREIGN KEY(tutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE SET NULL,
	FOREIGN KEY(cotutor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE SET NULL,
	FOREIGN KEY(alumno) REFERENCES alumnos(ID)
	ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS presentaciones(
	tfg TEXT,
	hora INT,
	dia INT,
	aula INT,
	slot INT,
	convocatoria INT,
	FOREIGN KEY(tfg) REFERENCES tfg(titulo)
	ON UPDATE CASCADE ON DELETE CASCADE,
	PRIMARY KEY(tfg, convocatoria)
);

CREATE TABLE IF NOT EXISTS tribunales(
	presentacion TEXT,
	profesor TEXT,
	FOREIGN KEY(presentacion) REFERENCES presentacion(idPresentacion)
	ON UPDATE CASCADE ON DELETE CASCADE,
	FOREIGN KEY(profesor) REFERENCES profesores(nombreCompleto)
	ON UPDATE CASCADE ON DELETE CASCADE,
	PRIMARY KEY(presentacion, profesor)
);