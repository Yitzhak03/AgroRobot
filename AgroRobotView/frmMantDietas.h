#pragma once
#include "frmNuevoDieta.h"
#include "frmEditarDieta.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmMantDietas
	/// </summary>
	public ref class frmMantDietas : public System::Windows::Forms::Form
	{
	public:
		frmMantDietas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->dietaController = gcnew GestorNutricionalController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantDietas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: GestorNutricionalController^ dietaController;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(578, 422);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantDietas::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(325, 422);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantDietas::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(42, 422);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantDietas::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 164);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(680, 235);
			this->dataGridView1->TabIndex = 7;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID Animal";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Fecha Inicio";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Alimentos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Frecuencia";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(24, 22);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(680, 122);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(317, 57);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantDietas::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(133, 57);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 63);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID:";
			this->label1->Click += gcnew System::EventHandler(this, &frmMantDietas::label1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(67, 141);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(172, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Enviar orden";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantDietas::button5_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->txtID);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(733, 22);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(317, 183);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Envio de órdenes";
			// 
			// txtID
			// 
			this->txtID->Location = System::Drawing::Point(157, 39);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(100, 22);
			this->txtID->TabIndex = 12;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(50, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 16);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Prioridad:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(50, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ID Dieta:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Alta", L"Media", L"Baja" });
			this->comboBox1->Location = System::Drawing::Point(157, 86);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMantDietas::comboBox1_SelectedIndexChanged);
			// 
			// frmMantDietas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1091, 679);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmMantDietas";
			this->Text = L"frmMantDietas";
			this->Load += gcnew System::EventHandler(this, &frmMantDietas::frmMantDietas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantDietas_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
		mostrarGrilla(listaDietas);
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   //================================================Nuevo============================================//
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoDieta^ nuevaDietaForm = gcnew frmNuevoDieta(this->dietaController);
		nuevaDietaForm->ShowDialog(this);
		List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
		mostrarGrilla(listaDietas);
	}

		   //================================================Eliminar============================================//
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{

			System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (resultado == System::Windows::Forms::DialogResult::No)
			{
				return;
			}

			int selectedRowIndex = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value);
			this->dietaController->eliminarDieta(id);
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			mostrarGrilla(listaDietas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   //================================================Buscar============================================//
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ textoBusqueda = textBox1->Text->Trim();

		// ?? Si no se ingresó nada, mostrar todas las dietas
		if (String::IsNullOrEmpty(textoBusqueda)) {
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			if (listaDietas->Count > 0) {
				mostrarGrilla(listaDietas);
			}
			else {
				MessageBox::Show("No hay dietas registradas.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			return;
		}

		// ?? Si sí se ingresó algo, intentar convertir a entero y buscar por ID
		int id = 0;
		try {
			id = Convert::ToInt32(textoBusqueda);
		}
		catch (FormatException^) {
			MessageBox::Show("Por favor, ingrese un ID válido (número entero).", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Dieta^ dietaSeleccionada = this->dietaController->consultarDietaporId(id);

		if (dietaSeleccionada != nullptr) {
			List<Dieta^>^ listaDietas = gcnew List<Dieta^>();
			listaDietas->Add(dietaSeleccionada);
			mostrarGrilla(listaDietas);
		}
		else {
			MessageBox::Show("No se encontró la dieta con el ID especificado.", "Búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}


		   //================================================Editar============================================//
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

			Dieta^ dietaSeleccionada = this->dietaController->consultarDietaporId(id);
			if (dietaSeleccionada == nullptr)
			{
				MessageBox::Show("No se encontró la dieta seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarDieta^ editarDietaForm = gcnew frmEditarDieta(this->dietaController, dietaSeleccionada);
			editarDietaForm->ShowDialog();
			// Llamar al m?todo para cargar la lista de maquinas nuevamente
			List<Dieta^>^ listaDietas = this->dietaController->obtenerTodasDietas();
			mostrarGrilla(listaDietas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	public:	void mostrarGrilla(List<Dieta^>^ listaDietas)
	{
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaDietas->Count; i++)
		{
			Dieta^ dieta = listaDietas[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(dieta->Id);
			filaGrilla[1] = Convert::ToString(dieta->IdAnimal);
			filaGrilla[2] = dieta->FechaInicio;
			filaGrilla[3] = dieta->Alimentos;
			filaGrilla[4] = dieta->Frecuencia;
			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (txtID->Text->Trim() == "") {
				MessageBox::Show("Por favor, ingrese el ID de la dieta antes de enviar la orden.",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int idDieta = Convert::ToInt32(txtID->Text);

			if (comboBox1->Text->Trim() == "") {
				MessageBox::Show("Seleccione una prioridad para la orden (Alta, Media, Baja).",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			String^ prioridad = comboBox1->Text;

			System::Windows::Forms::DialogResult confirmacion =
				MessageBox::Show("¿Desea enviar esta orden al módulo de Almacén?",
					"Confirmar envío", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (confirmacion == System::Windows::Forms::DialogResult::No) {
				return;
			}

			this->dietaController->enviarOrdenAlimentacion(idDieta, prioridad);

			MessageBox::Show("La orden de alimentación fue enviada correctamente al módulo de Almacén.",
				"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			txtID->Clear();
			comboBox1->SelectedIndex = -1;
		}
		catch (FormatException^) {
			MessageBox::Show("El ID ingresado no tiene un formato válido. Debe ser un número entero.",
				"Error de formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error inesperado al enviar la orden:\n" + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
