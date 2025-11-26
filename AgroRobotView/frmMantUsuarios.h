#pragma once
#include "frmNuevoUsuario.h"
#include "frmEditarUsuario.h"

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

	public ref class frmMantUsuarios : public System::Windows::Forms::Form {
	public:
		frmMantUsuarios(void)
		{
			InitializeComponent();
			this->usuarioController = gcnew UsuarioController();
			this->rolController = gcnew RolController();

			// APLICAR ESTILO MENTA/BOSQUE
			aplicarEstilo();
		}

	protected:
		~frmMantUsuarios()
		{
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button^ btnMostrarTodos;
		System::Windows::Forms::Button^ btnCambiarEstado;
		System::Windows::Forms::Button^ btnEditar;
		System::Windows::Forms::Button^ button2; // Nuevo
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Button^ btnBuscar;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::ComboBox^ comboBox1;

		// Columnas
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;

		UsuarioController^ usuarioController;
		RolController^ rolController;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnMostrarTodos = (gcnew System::Windows::Forms::Button());
			this->btnCambiarEstado = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();

			// btnMostrarTodos
			this->btnMostrarTodos->Location = System::Drawing::Point(582, 49);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(120, 35);
			this->btnMostrarTodos->TabIndex = 16;
			this->btnMostrarTodos->Text = L"Mostrar Todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = true;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnMostrarTodos_Click);

			// btnCambiarEstado
			this->btnCambiarEstado->Location = System::Drawing::Point(526, 370);
			this->btnCambiarEstado->Name = L"btnCambiarEstado";
			this->btnCambiarEstado->Size = System::Drawing::Size(120, 35);
			this->btnCambiarEstado->TabIndex = 15;
			this->btnCambiarEstado->Text = L"Cambiar Estado";
			this->btnCambiarEstado->UseVisualStyleBackColor = true;
			this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnCambiarEstado_Click);

			// btnEditar
			this->btnEditar->Location = System::Drawing::Point(362, 370);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(120, 35);
			this->btnEditar->TabIndex = 14;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = true;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnEditar_Click);

			// button2 (Nuevo)
			this->button2->Location = System::Drawing::Point(200, 370);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 35);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Nuevo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantUsuarios::button2_Click);

			// dataGridView1
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^ >(7) {
				this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(11, 135);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(804, 198);
			this->dataGridView1->TabIndex = 12;

			// Columnas
			this->Column1->HeaderText = L"Id"; this->Column1->Visible = false;
			this->Column2->HeaderText = L"Nombre";
			this->Column3->HeaderText = L"Email";
			this->Column4->HeaderText = L"Contraseña";
			this->Column5->HeaderText = L"Último Acceso";
			this->Column6->HeaderText = L"Estado";
			this->Column7->HeaderText = L"Rol";

			// groupBox1
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->btnMostrarTodos);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(804, 101);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";

			// comboBox1
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^ >(2) { L"Habilitado", L"Deshabilitado" });
			this->comboBox1->Location = System::Drawing::Point(326, 50);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(128, 21);
			this->comboBox1->TabIndex = 17;

			// btnBuscar
			this->btnBuscar->Location = System::Drawing::Point(493, 50);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(120, 35);
			this->btnBuscar->TabIndex = 4;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnBuscar_Click);

			// label2
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(278, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Estado:";

			// textBox1
			this->textBox1->Location = System::Drawing::Point(86, 50);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(128, 20);
			this->textBox1->TabIndex = 1;

			// label1
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre :";

			// frmMantUsuarios
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(827, 439);
			this->Controls->Add(this->btnCambiarEstado);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantUsuarios";
			this->Text = L"Gestión de Usuarios";
			this->Load += gcnew System::EventHandler(this, &frmMantUsuarios::frmMantUsuarios_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

		// =========================================================
		// APLICAR DISEÑO "MENTA/BOSQUE" (COMO EN INSUMOS)
		// =========================================================
		void aplicarEstilo()
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
			this->Text = "Gestión de Usuarios";

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
			array<Label^>^ labels = { label1, label2 };
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
			textBox1->Location = Point(startX + 60, yControl); textBox1->Width = 130;

			label2->Location = Point(startX + 210, yControl + 4);
			comboBox1->Location = Point(startX + 270, yControl); comboBox1->Width = 130;

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
			array<Button^>^ botonesCRUD = { button2, btnEditar, btnCambiarEstado };
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

		// =========================================================
		// LÓGICA DE NEGOCIO (SIN CAMBIOS)
		// =========================================================
	public:	void mostrarGrilla(List<Usuario^>^ listaUsuarios)
	{
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaUsuarios->Count; i++)
		{
			Usuario^ usuario = listaUsuarios[i];
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			filaGrilla[0] = Convert::ToString(usuario->GetId());
			filaGrilla[1] = usuario->GetNombre();
			filaGrilla[2] = usuario->GetEmail();
			filaGrilla[3] = usuario->GetContrasenha();
			filaGrilla[4] = Convert::ToString(usuario->GetUltimoAcceso());
			(usuario->GetEstadoCuenta()) ? filaGrilla[5] = "Habilitado" : filaGrilla[5] = "Desabilitado";
			filaGrilla[6] = usuario->GetRol()->GetNombre();
			this->dataGridView1->Rows->Add(filaGrilla);
		}
		this->dataGridView1->AutoGenerateColumns = false;
		this->dataGridView1->AllowUserToAddRows = false;
		this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
	}

	private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dataGridView1->Rows->Clear();
		List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
		if (comboBox1->Text == "Habilitado") listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();
		else if (comboBox1->Text == "Deshabilitado") listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados();
		else MessageBox::Show("Por favor, seleccione un estado para mostrar todos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		mostrarGrilla(listaUsuarios);
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		frmNuevoUsuario^ nuevoUsuarioForm = gcnew frmNuevoUsuario(this->usuarioController);
		nuevoUsuarioForm->ShowDialog();
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombreUsuario = textBox1->Text;
		String^ estadoTexto = comboBox1->Text;
		Nullable<bool> estadoUsuario;
		if (estadoTexto == "Habilitado") estadoUsuario = true;
		else if (estadoTexto == "Deshabilitado") estadoUsuario = false;
		List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
		if (nombreUsuario != "") listaUsuarios = this->usuarioController->obtenerUsuarioPorNombreEstado(nombreUsuario, estadoUsuario);
		mostrarGrilla(listaUsuarios);
	}

	private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0) {
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int idUsuario = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);
			Usuario^ usuarioSeleccionado = this->usuarioController->obtenerUsuarioPorId(idUsuario);
			System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de cambiar el estado?", "Confirmación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			if (resultado == System::Windows::Forms::DialogResult::No) return;
			this->usuarioController->cambiarEstadoUsuario(idUsuario);
			List<Usuario^>^ listaUsuarios;
			(usuarioSeleccionado->GetEstadoCuenta()) ? listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados() : listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();
			mostrarGrilla(listaUsuarios);
		}
		else MessageBox::Show("Seleccione un usuario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count > 0) {
			int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
			int idUsuario = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);
			Usuario^ usuarioSeleccionado = this->usuarioController->obtenerUsuarioPorId(idUsuario);
			if (usuarioSeleccionado == nullptr) return;
			if (usuarioSeleccionado->GetEstadoCuenta() == false) { MessageBox::Show("No se puede editar usuario deshabilitado."); return; }
			frmEditarUsuario^ ventana = gcnew frmEditarUsuario(this->usuarioController, usuarioSeleccionado, this->rolController);
			ventana->ShowDialog();
			List<Usuario^>^ listaUsuarios;
			if (usuarioSeleccionado->GetEstadoCuenta()) listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();
			else listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados();
			mostrarGrilla(listaUsuarios);
		}
		else MessageBox::Show("Seleccione un usuario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	private: System::Void frmMantUsuarios_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}