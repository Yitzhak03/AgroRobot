#pragma once
#include "frmNuevoMuestraS.h"
#include "frmEditarMuestraS.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmMantSangre
	/// </summary>
	public ref class frmMantSangre : public System::Windows::Forms::Form
	{
	public:
		frmMantSangre(void)
		{
			InitializeComponent();
			this->muestraController = gcnew MuestraController();
			this->gestorNutricionalController = gcnew GestorNutricionalController();
			cargarAnimalesDisponibles();
			cargarAnimalesSinMuestraSangre();
			this->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->BackColor = System::Drawing::Color::LightGreen;
			this->button1->ForeColor = System::Drawing::Color::DarkGreen;
			this->button2->BackColor = System::Drawing::Color::LightGreen;
			this->button2->ForeColor = System::Drawing::Color::DarkGreen;
			this->button3->BackColor = System::Drawing::Color::LightGreen;
			this->button3->ForeColor = System::Drawing::Color::DarkGreen;
			this->button4->BackColor = System::Drawing::Color::LightGreen;
			this->button4->ForeColor = System::Drawing::Color::DarkGreen;
			this->button5->BackColor = System::Drawing::Color::LightGreen;
			this->button5->ForeColor = System::Drawing::Color::DarkGreen;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantSangre()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button3;







	private: GestorNutricionalController^ gestorNutricionalController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: MuestraController^ muestraController;
	private: System::Windows::Forms::DataGridView^ dataGridView1;







	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;



































































	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(384, 357);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantSangre::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 357);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantSangre::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(49, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(318, 100);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(87, 71);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(137, 23);
			this->button5->TabIndex = 32;
			this->button5->Text = L"Limpiar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantSangre::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(210, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantSangre::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Animal:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(34, 153);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(566, 180);
			this->dataGridView1->TabIndex = 28;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(400, 24);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 100);
			this->groupBox2->TabIndex = 29;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Nueva Muestra Sangre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"ID Animal:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(93, 32);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(77, 21);
			this->comboBox1->TabIndex = 27;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 23);
			this->button2->TabIndex = 26;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantSangre::button2_Click_1);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Muestra";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Especie";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Cantidad Extraída";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Presencia de Coágulos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Contaminación Visible";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Color";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Fecha";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 125;
			// 
			// frmMantSangre
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 405);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantSangre";
			this->Text = L"AgroRobot - Gestión de Muestras de Sangre";
			this->Load += gcnew System::EventHandler(this, &frmMantSangre::frmMantSangre_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void cargarAnimalesDisponibles() {
		this->comboBox1->Items->Clear();

		// Obtener todos los animales
		List<Animal^>^ todosAnimales = gestorNutricionalController->obtenerTodosAnimales();
		// Obtener todas las muestras
		List<Muestra^>^ todasMuestras = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);

		for each (Animal ^ a in todosAnimales) {
			bool tieneSangre = false;
			for each (Muestra ^ m in todasMuestras) {
				if (m->getAnimal() != nullptr &&
					m->getAnimal()->IdAnimal == a->IdAnimal &&
					m->getTipo()->Equals("Sangre")) {
					tieneSangre = true;
					break;
				}
			}
			if (!tieneSangre) {
				this->comboBox1->Items->Add(a->IdAnimal);
			}
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textoId = this->textBox1->Text->Trim();
		int idAnimal;

		//MuestraController^ controller = gcnew MuestraController();
		List<Muestra^>^ listaFiltrada = gcnew List<Muestra^>();

		if (String::IsNullOrEmpty(textoId)) {
			// Mostrar todas las muestras de sangre
			List<Muestra^>^ todas = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}
		else {

			if (!Int32::TryParse(textoId, idAnimal)) {
				MessageBox::Show("Ingrese un ID de animal válido.");
				return;
			}
			List<Muestra^>^ listaMuestras = muestraController->buscarMuestrasPorAnimalArchivo(idAnimal, gestorNutricionalController);
			for each (Muestra ^ m in listaMuestras) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
		}

		this->dataGridView1->Rows->Clear();
		if (listaFiltrada->Count == 0) {
			MessageBox::Show("No se encontraron muestras de sangre.");
		}
		else {
			mostrarGrilla(listaFiltrada);
		}
	}

	private: void mostrarGrilla(List<Muestra^> ^ listaMuestras) {
		for (int i = 0; i < listaMuestras->Count; i++) {
			Muestra^ m = listaMuestras[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(m->getIdMuestra());
			filaGrilla[1] = m->getEspecie();
			filaGrilla[2] = m->getCantidadExtraida();
			filaGrilla[3] = m->getCoagulos();
			filaGrilla[4] = m->getContaminacion();
			filaGrilla[5] = m->getColorSangre();
			filaGrilla[6] = m->getFechaToma();
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una fila para editar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idMuestraEditar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		// Usar el gestor para reconstruir la muestra correctamente
		Muestra^ muestra = this->muestraController->buscarMuestraPorIdArchivo(idMuestraEditar, this->gestorNutricionalController);

		if (muestra == nullptr || !muestra->getTipo()->Equals("Sangre")) {
			MessageBox::Show("La muestra seleccionada no es válida o no es de tipo sangre.");
			return;
		}

		// Abrir formulario de edición de muestra de sangre
		frmEditarMuestraS^ ventanaEditar = gcnew frmEditarMuestraS(muestra, this->muestraController);
		ventanaEditar->ShowDialog();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una muestra para eliminar.");
			return;
		}

		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int idEliminar = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());

		// Confirmación antes de eliminar
		System::Windows::Forms::DialogResult resultado =
			MessageBox::Show("¿Está seguro de que desea eliminar la muestra seleccionada?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning);

		if (resultado == System::Windows::Forms::DialogResult::Yes) {
			this->muestraController->eliminarMuestraArchivo(idEliminar);
			MessageBox::Show("La muestra ha sido eliminada con éxito.");

			// Refrescar la grilla mostrando solo muestras de sangre
			List<Muestra^>^ todas = this->muestraController->buscarTodasMuestrasArchivo(this->gestorNutricionalController);
			List<Muestra^>^ listaFiltrada = gcnew List<Muestra^>();
			for each (Muestra ^ m in todas) {
				if (m->getTipo()->Equals("Sangre")) {
					listaFiltrada->Add(m);
				}
			}
			this->dataGridView1->Rows->Clear();
			mostrarGrilla(listaFiltrada);
			cargarAnimalesSinMuestraSangre();
		}
	}

	private: System::Void frmMantSangre_Load(System::Object^ sender, System::EventArgs^ e) {
		
		List<Muestra^>^ todas = this->muestraController->buscarTodasMuestrasArchivo(this->gestorNutricionalController);
		List<Muestra^>^ listaSangre = gcnew List<Muestra^>();
		for each (Muestra ^ m in todas) {
			if (m->getTipo()->Equals("Sangre")) {
				listaSangre->Add(m);
			}
		}
		this->dataGridView1->Rows->Clear();
		mostrarGrilla(listaSangre);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Clear();
	}

	private: void cargarAnimalesSinMuestraSangre() {
		
		List<Animal^>^ animales = gestorNutricionalController->leerArchivoAnimal();
		List<Muestra^>^ muestras = muestraController->buscarTodasMuestrasArchivo(gestorNutricionalController);

		this->comboBox1->Items->Clear();

		for each (Animal ^ a in animales) {
			bool tieneMuestraSangre = false;
			for each (Muestra ^ m in muestras) {
				if (m->getIdAnimal() == a->IdAnimal && m->getTipo()->Equals("Sangre")) {
					tieneMuestraSangre = true;
					break;
				}
			}
			if (!tieneMuestraSangre) {
				this->comboBox1->Items->Add(a->IdAnimal);
			}
		}
	}

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->SelectedItem == nullptr) {
			MessageBox::Show("Seleccione un animal válido antes de agregar una muestra de sangre.");
			return;
		}

		int idAnimalSeleccionado = Convert::ToInt32(this->comboBox1->SelectedItem->ToString());

		// Abrir el formulario de nueva muestra de sangre
		frmNuevoMuestraS^ nuevaMuestraSangre = gcnew frmNuevoMuestraS(
			idAnimalSeleccionado,
			this->muestraController,
			this->gestorNutricionalController
		);

		nuevaMuestraSangre->ShowDialog();

		// Refrescar comboBox después de agregar
		cargarAnimalesDisponibles();
	}
};
}
