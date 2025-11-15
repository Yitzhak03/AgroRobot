#pragma once
#include "frmNuevoRol.h"
#include "frmEditarRol.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmMantRoles
	/// </summary>
	public ref class frmMantRoles : public System::Windows::Forms::Form
	{
	public:
		frmMantRoles(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->rolController = gcnew RolController();
			aplicarEstilo();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantRoles()
		{
			if (components)
			{
				delete components;
			}
		}

		void aplicarEstilo()
		{
			this->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);

			this->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10, FontStyle::Regular);
			this->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);

			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(45, 93, 80);
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(242, 242, 242);
			this->groupBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11, FontStyle::Bold);
			this->groupBox1->Text = L"Criterios de búsqueda";

			array<TextBox^>^ textos = { this->txtBuscar};
			for each (TextBox ^ t in textos) {
				t->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
				t->ForeColor = System::Drawing::Color::White;
				t->BorderStyle = BorderStyle::FixedSingle;
				t->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			}

			this->button1->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			this->button1->FlatStyle = FlatStyle::Flat;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);


			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(45, 93, 80);
			this->dataGridView1->BorderStyle = BorderStyle::None;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(30, 61, 54);
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 61, 54);
			this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(60, 110, 95);
			this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(123, 228, 149);
			this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;

			array<Button^>^ botones = { this->button2, this->button3, this->btnEliminar, this->btnBuscar, this->btnMostrarTodos};
			for each (Button ^ b in botones) {
				b->BackColor = System::Drawing::Color::FromArgb(123, 228, 149);
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 10);
				b->ForeColor = System::Drawing::Color::Black;
				b->Cursor = Cursors::Hand;
			}

			// 🏷️ Etiquetas
			array<Label^>^ labels = { this->label1};
			for each (Label ^ l in labels) {
				l->ForeColor = System::Drawing::Color::White;
				l->Font = gcnew System::Drawing::Font(L"Bahnschrift", 10);
			}

			// 📏 Config general
			this->Text = L"AgroRobot - Mantenimiento de Roles";
			this->StartPosition = FormStartPosition::CenterScreen;
		}
	
	private: RolController^ rolController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBuscar;

	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnMostrarTodos;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;



















	protected:

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnMostrarTodos = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnMostrarTodos);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtBuscar);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(575, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->Location = System::Drawing::Point(447, 41);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(80, 35);
			this->btnMostrarTodos->TabIndex = 17;
			this->btnMostrarTodos->Text = L"Mostrar Todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = true;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmMantRoles::btnMostrarTodos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(370, 49);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(56, 19);
			this->btnBuscar->TabIndex = 5;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantRoles::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(49, 49);
			this->txtBuscar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(128, 20);
			this->txtBuscar->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 52);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Id:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 129);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(575, 229);
			this->dataGridView1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(41, 381);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Nuevo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantRoles::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(475, 381);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantRoles::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(182, 381);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantRoles::button3_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(330, 381);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(75, 23);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantRoles::btnEliminar_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 30;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Rol";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Administrar Usuarios";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Acceso a Reportes";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 130;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Acceso a Alimentación";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 125;
			// 
			// frmMantRoles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(599, 430);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantRoles";
			this->Text = L"Gestión de Roles";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:	void mostrarGrilla(List<Rol^>^ listaRoles)
		{
			this->dataGridView1->Rows->Clear();
			for (int i = 0; i < listaRoles->Count; i++)
			{
				Rol^ rol = listaRoles[i];
				array<String^>^ filaGrilla = gcnew array<String^>(7);
				filaGrilla[0] = Convert::ToString(rol->GetId());
				filaGrilla[1] = rol->GetNombre();

				List<bool>^ listaPermisos = rol->GetPermisos();
				
				for (int j = 0; j < listaPermisos->Count; j++) {
					if (listaPermisos[j]) {
						filaGrilla[j + 2] = "Permitido";
					}
					else {
						filaGrilla[j + 2] = "Denegado";
					}
				}

				this->dataGridView1->Rows->Add(filaGrilla);
			}

			this->dataGridView1->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
			this->dataGridView1->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		}

		private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e) {
			this->dataGridView1->Rows->Clear();

			List<Rol^>^ listaRoles = this->rolController->obtenerTodosRoles();
			mostrarGrilla(listaRoles);
		}
	
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			frmNuevoRol^ nuevoRolForm = gcnew frmNuevoRol(this->rolController);
			nuevoRolForm->ShowDialog();
		}
		
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->dataGridView1->SelectedRows->Count > 0)
			{
				int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
				int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

				Rol^ rolSeleccionado= this->rolController->obtenerRolPorId(id);
				if (rolSeleccionado == nullptr)
				{
					MessageBox::Show("No se encontró el rol seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				// Crear una nueva instancia del formulario de nuevo operador
				// y mostrarlo como un formulario hijo dentro del contenedor MDI
				frmEditarRol^ editarRolForm = gcnew frmEditarRol(this->rolController, rolSeleccionado);
				editarRolForm->ShowDialog();
				// Llamar al m�todo para cargar la lista de roles nuevamente
				List<Rol^>^ listaRoles= this->rolController->obtenerTodosRoles();
				mostrarGrilla(listaRoles);
			}
			else
			{
				MessageBox::Show("Por favor, seleccione un rol para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->dataGridView1->SelectedRows->Count > 0) {
				// Preguntar al usuario si est� seguro de eliminar el registro
				System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
					"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

				// Si el usuario selecciona "No", cancelar la operaci�n
				if (resultado == System::Windows::Forms::DialogResult::No) {
					return; // Salir del evento si el usuario cancela
				}

				int selectedRowIndex = this->dataGridView1->SelectedRows[0]->Index;
				int id = Convert::ToInt32(this->dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value);
				// Crear una instancia del controlador y eliminar el rol
				this->rolController->eliminarRol(id);
				// Actualizar la lista de roles en el DataGridView
				List<Rol^>^ listaRoles = this->rolController->obtenerTodosRoles();
				mostrarGrilla(listaRoles);
			}
			else {
				MessageBox::Show("Por favor, seleccione un usuario para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Rol^>^ listaRoles = gcnew List<Rol^>();
		/*si no se ingresa nada para buscar no busca nada*/
		if (this->txtBuscar->Text != ""){
			int id = 0;
			/*verifica que haya un entero en la casilla de búsqueda*/
			if (Int32::TryParse(this->txtBuscar->Text, id)) {
				Rol^ rol = this -> rolController->obtenerRolPorId(id);
				
				if (rol != nullptr) {
					listaRoles->Add(rol);
				}
			}
			else {
				MessageBox::Show("Por favor, ingrese un ID válido para buscar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		mostrarGrilla(listaRoles);
	}
};
}
