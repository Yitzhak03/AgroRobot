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
			aplicarFormato();
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

		void aplicarFormato()
		{
			// 1. PALETA DE COLORES
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248); // Blanco Menta
			System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Suave
			System::Drawing::Color colorVerdeOscuro = System::Drawing::Color::FromArgb(64, 106, 90); // Texto Títulos
			System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(22, 53, 45);      // Texto Normal
			System::Drawing::Color colorBotonPrimario = System::Drawing::Color::FromArgb(46, 143, 77); // Verde Esmeralda
			System::Drawing::Color colorBotonSecundario = System::Drawing::Color::FromArgb(236, 246, 240); // Menta Botón
			System::Drawing::Color colorBordeBoton = System::Drawing::Color::FromArgb(203, 233, 217);

			// 2. FUENTES
			System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 9, FontStyle::Bold);
			System::Drawing::Font^ fuenteLabel = gcnew System::Drawing::Font("Microsoft Tai Le", 8.25F, FontStyle::Bold);
			System::Drawing::Font^ fuenteGridHeader = gcnew System::Drawing::Font("Segoe UI Semibold", 10);
			System::Drawing::Font^ fuenteGridCell = gcnew System::Drawing::Font("Microsoft Sans Serif", 9);

			// 3. CONFIGURACIÓN FORMULARIO
			this->BackColor = colorFondo;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = "Gestión de Roles";

			// 4. GROUP BOX (BÚSQUEDA)
			int margenLateral = 30;

			this->groupBox1->BackColor = colorPanel;
			this->groupBox1->ForeColor = colorVerdeOscuro;
			this->groupBox1->Font = fuenteTitulo;
			this->groupBox1->FlatStyle = FlatStyle::System; // Para que tome el color

			this->groupBox1->Location = System::Drawing::Point(margenLateral, 20);
			this->groupBox1->Height = 100;
			this->groupBox1->Width = this->ClientSize.Width - (margenLateral * 2);
			this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);

			// Controles dentro del GroupBox
			array<Label^>^ labels = { label1 };
			for each (Label ^ l in labels) {
				l->Font = fuenteLabel;
				l->ForeColor = colorVerdeOscuro;
			}

			// Botón Buscar (Primario)
			this->btnBuscar->BackColor = colorBotonPrimario;
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->FlatStyle = FlatStyle::Flat;
			this->btnBuscar->FlatAppearance->BorderSize = 0;
			this->btnBuscar->Font = fuenteTitulo;
			this->btnBuscar->Cursor = Cursors::Hand;

			// Botón Mostrar Todos (Secundario pero en panel claro)
			this->btnMostrarTodos->BackColor = System::Drawing::Color::White; // Contraste sobre el panel menta
			this->btnMostrarTodos->ForeColor = colorVerdeOscuro;
			this->btnMostrarTodos->FlatStyle = FlatStyle::Flat;
			this->btnMostrarTodos->FlatAppearance->BorderColor = colorBordeBoton;
			this->btnMostrarTodos->Font = fuenteTitulo;
			this->btnMostrarTodos->Cursor = Cursors::Hand;

			// Centrar controles dentro del GroupBox (Cálculo)
			int startX = (this->groupBox1->Width - (50 + 130 + 30 + 50 + 130 + 30 + 100 + 20 + 120)) / 2;
			if (startX < 10) startX = 10;
			int yControl = 45;

			label1->Location = Point(startX, yControl + 4);
			txtBuscar->Location = Point(startX + 60, yControl); txtBuscar->Width = 130;

			btnBuscar->Location = Point(startX + 430, yControl - 5);
			btnMostrarTodos->Location = Point(startX + 550, yControl - 5);

			// 5. GRILLA (DATAGRIDVIEW)
			int yGrilla = this->groupBox1->Bottom + 20;
			int hFooter = 70;

			this->dataGridView1->Location = Point(margenLateral, yGrilla);
			this->dataGridView1->Width = this->ClientSize.Width - (margenLateral * 2);
			this->dataGridView1->Height = this->ClientSize.Height - yGrilla - hFooter;
			this->dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			// Estilo Visual Grilla
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = BorderStyle::None;
			this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(183, 220, 200); // Líneas verdes suaves

			// Cabecera
			this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorPanel; // Menta suave
			this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = colorTexto;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = fuenteGridHeader;
			this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeight = 40;

			// Filas
			this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			this->dataGridView1->DefaultCellStyle->ForeColor = colorTexto;
			this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::LightGreen;
			this->dataGridView1->DefaultCellStyle->SelectionForeColor = colorTexto;
			this->dataGridView1->DefaultCellStyle->Font = fuenteGridCell;
			this->dataGridView1->RowTemplate->Height = 35;
			this->dataGridView1->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(244, 250, 246); // Alternado muy sutil

			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// 6. BOTONES INFERIORES (CRUD - Secundarios)
			int yBotones = this->ClientSize.Height - 55;
			array<Button^>^ botonesCRUD = { btnEliminar, button1, button2, button3 };
			int xBtn = margenLateral;

			for each (Button ^ btn in botonesCRUD) {
				btn->BackColor = colorBotonSecundario;
				btn->ForeColor = colorVerdeOscuro;
				btn->FlatStyle = FlatStyle::Flat;
				btn->FlatAppearance->BorderColor = colorBordeBoton;
				btn->Font = fuenteTitulo;
				btn->Cursor = Cursors::Hand;
				btn->Height = 39; // Altura estándar del diseño

				btn->Location = Point(xBtn, yBotones);
				btn->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);

				xBtn += btn->Width + 15;
			}
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
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
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
			this->groupBox1->Location = System::Drawing::Point(16, 15);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(767, 123);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterio de Búsqueda";
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->Location = System::Drawing::Point(445, 51);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(158, 43);
			this->btnMostrarTodos->TabIndex = 17;
			this->btnMostrarTodos->Text = L"Mostrar Todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = true;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmMantRoles::btnMostrarTodos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(338, 51);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(112, 43);
			this->btnBuscar->TabIndex = 5;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantRoles::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(65, 60);
			this->txtBuscar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(169, 22);
			this->txtBuscar->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 16);
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
			this->dataGridView1->Location = System::Drawing::Point(16, 159);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(767, 282);
			this->dataGridView1->TabIndex = 1;
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 469);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Nuevo";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantRoles::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(633, 469);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantRoles::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(243, 469);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 28);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantRoles::button3_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(440, 469);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(100, 28);
			this->btnEliminar->TabIndex = 5;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantRoles::btnEliminar_Click);
			// 
			// frmMantRoles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 529);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->AllowUserToAddRows = false;
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
