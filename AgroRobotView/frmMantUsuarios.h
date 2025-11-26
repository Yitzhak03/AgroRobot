	#pragma once
	#include "frmNuevoUsuario.h"
	#include "frmEditarUsuario.h"
	namespace AgroRobotView {

		using namespace System;
		using namespace System::ComponentModel;
		using namespace System::Collections;
		using namespace System::Collections::Generic; // Para usar List<>
		using namespace System::Windows::Forms;
		using namespace System::Data;
		using namespace System::Drawing;
		using namespace AgroRobotController;
		using namespace AgroRobotModel;

		/// <summary>
		/// Resumen de frmMantUsuarios
		/// </summary>
		public ref class frmMantUsuarios : public System::Windows::Forms::Form {
		public:
			frmMantUsuarios(void)
			{
				InitializeComponent();
				//
				//TODO: agregar código de constructor aquí
				//
				this->usuarioController = gcnew UsuarioController();
				this->rolController = gcnew RolController();
				aplicarEstilo();
			}

		protected:
			/// <summary>
			/// Limpiar los recursos que se estén usando.
			/// </summary>
			~frmMantUsuarios()
			{
				if (components) {
					delete components;
				}
			}

			void aplicarEstilo()
			{
				// 1. COLORES (Tus colores originales)
				System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(30, 61, 54);
				System::Drawing::Color colorPanel = System::Drawing::Color::FromArgb(45, 93, 80);
				System::Drawing::Color colorInput = System::Drawing::Color::FromArgb(60, 110, 95);
				System::Drawing::Color colorVerdeClaro = System::Drawing::Color::FromArgb(123, 228, 149);
				System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(242, 242, 242);

				this->BackColor = colorFondo;
				this->ForeColor = colorTexto;

				// 2. ESCALADO DE FUENTE GENERAL (Cambio de 10 a 12)
				this->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12, FontStyle::Regular);

				// 3. CONFIGURACIÓN DEL FORMULARIO (Maximizar y permitir redimensionar)
				this->Text = L"AgroRobot - Mantenimiento de Usuarios";
				this->StartPosition = FormStartPosition::CenterScreen;
				this->WindowState = FormWindowState::Maximized; // Iniciar en pantalla completa (Opcional)

				// --- GROUP BOX (BÚSQUEDA) ---
				this->groupBox1->BackColor = colorPanel;
				this->groupBox1->ForeColor = colorTexto;
				this->groupBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 13, FontStyle::Bold); // Fuente más grande
				this->groupBox1->Text = L"Criterios de búsqueda";
				// ANCLAJE: Se estira a la izquierda y derecha
				this->groupBox1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right);
				this->groupBox1->Width = this->ClientSize.Width - 22; // Ajuste inicial al ancho

				// Controles dentro del GroupBox
				this->textBox1->BackColor = colorInput;
				this->textBox1->ForeColor = System::Drawing::Color::White;
				this->textBox1->BorderStyle = BorderStyle::FixedSingle;
				this->textBox1->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12); // Más grande

				this->btnBuscar->BackColor = colorVerdeClaro;
				this->btnBuscar->FlatStyle = FlatStyle::Flat;
				this->btnBuscar->FlatAppearance->BorderSize = 0;
				this->btnBuscar->ForeColor = System::Drawing::Color::Black;
				this->btnBuscar->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 12);
				// ANCLAJE: El botón buscar se queda pegado a la derecha si agrandas el groupbox (opcional)
				// this->btnBuscar->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right); 

				this->btnMostrarTodos->BackColor = colorVerdeClaro;
				this->btnMostrarTodos->FlatStyle = FlatStyle::Flat;
				this->btnMostrarTodos->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 11);
				this->btnMostrarTodos->Size = System::Drawing::Size(120, 35); // Botón más grande

				// --- DATAGRIDVIEW (TABLA) ---
				this->dataGridView1->BackgroundColor = colorPanel;
				this->dataGridView1->BorderStyle = BorderStyle::None;
				this->dataGridView1->GridColor = colorFondo;
				this->dataGridView1->EnableHeadersVisualStyles = false;

				// Estilo de Cabecera
				this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = colorFondo;
				this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
				this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12, FontStyle::Bold);
				this->dataGridView1->ColumnHeadersHeight = 40; // Cabecera más alta

				// Estilo de Celdas
				this->dataGridView1->DefaultCellStyle->BackColor = colorInput;
				this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
				this->dataGridView1->DefaultCellStyle->SelectionBackColor = colorVerdeClaro;
				this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
				this->dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Bahnschrift", 11);
				this->dataGridView1->RowTemplate->Height = 35; // Filas más altas para que quepa la letra grande

				// ANCLAJE TOTAL: Se estira en las 4 direcciones al agrandar la ventana
				this->dataGridView1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

				// COLUMNAS AUTO-AJUSTABLES (Llenan el espacio)
				this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

				// --- BOTONES INFERIORES ---
				array<Button^>^ botonesAccion = { this->button2, this->btnCambiarEstado, this->btnEditar };

				// Calculamos una posición base para centrarlos o dejarlos a la izquierda
				int espacio = 20;
				int xInicial = 200;

				for each (Button ^ b in botonesAccion) {
					b->BackColor = colorVerdeClaro;
					b->FlatStyle = FlatStyle::Flat;
					b->FlatAppearance->BorderSize = 0;
					b->Font = gcnew System::Drawing::Font(L"Bahnschrift SemiBold", 12);
					b->ForeColor = System::Drawing::Color::Black;
					b->Cursor = Cursors::Hand;
					b->Size = System::Drawing::Size(140, 40); // Botones más grandes y cómodos

					// ANCLAJE INFERIOR: Se quedan pegados abajo a la izquierda
					b->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom | AnchorStyles::Left);
				}

				// Ajuste de etiquetas
				array<Label^>^ labels = { this->label1, this->label2 };
				for each (Label ^ l in labels) {
					l->ForeColor = System::Drawing::Color::White;
					l->Font = gcnew System::Drawing::Font(L"Bahnschrift", 12);
				}
			}

		private: System::Windows::Forms::Button^ btnMostrarTodos;
		private: System::Windows::Forms::Button^ btnCambiarEstado;

		private: System::Windows::Forms::Button^ btnEditar;
		protected:

		protected:


		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::DataGridView^ dataGridView1;






		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::Button^ btnBuscar;


		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::Label^ label1;







		private: UsuarioController^ usuarioController;
		private: RolController^ rolController;






		private: System::Windows::Forms::ComboBox^ comboBox1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
		private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
























		protected:


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
				// 
				// btnMostrarTodos
				// 
				this->btnMostrarTodos->Location = System::Drawing::Point(582, 49);
				this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(2);
				this->btnMostrarTodos->Name = L"btnMostrarTodos";
				this->btnMostrarTodos->Size = System::Drawing::Size(92, 30);
				this->btnMostrarTodos->TabIndex = 16;
				this->btnMostrarTodos->Text = L"Mostrar Todos";
				this->btnMostrarTodos->UseVisualStyleBackColor = true;
				this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnMostrarTodos_Click);
				// 
				// btnCambiarEstado
				// 
				this->btnCambiarEstado->Location = System::Drawing::Point(526, 370);
				this->btnCambiarEstado->Margin = System::Windows::Forms::Padding(2);
				this->btnCambiarEstado->Name = L"btnCambiarEstado";
				this->btnCambiarEstado->Size = System::Drawing::Size(99, 19);
				this->btnCambiarEstado->TabIndex = 15;
				this->btnCambiarEstado->Text = L"Cambiar Estado";
				this->btnCambiarEstado->UseVisualStyleBackColor = true;
				this->btnCambiarEstado->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnCambiarEstado_Click);
				// 
				// btnEditar
				// 
				this->btnEditar->Location = System::Drawing::Point(362, 370);
				this->btnEditar->Margin = System::Windows::Forms::Padding(2);
				this->btnEditar->Name = L"btnEditar";
				this->btnEditar->Size = System::Drawing::Size(56, 19);
				this->btnEditar->TabIndex = 14;
				this->btnEditar->Text = L"Editar";
				this->btnEditar->UseVisualStyleBackColor = true;
				this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnEditar_Click);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(200, 370);
				this->button2->Margin = System::Windows::Forms::Padding(2);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(56, 19);
				this->button2->TabIndex = 13;
				this->button2->Text = L"Nuevo";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &frmMantUsuarios::button2_Click);
				// 
				// dataGridView1
				// 
				this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
					this->Column1,
						this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
				});
				this->dataGridView1->Location = System::Drawing::Point(11, 135);
				this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
				this->dataGridView1->MultiSelect = false;
				this->dataGridView1->Name = L"dataGridView1";
				this->dataGridView1->RowHeadersWidth = 51;
				this->dataGridView1->RowTemplate->Height = 24;
				this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
				this->dataGridView1->Size = System::Drawing::Size(804, 198);
				this->dataGridView1->TabIndex = 12;
				// 
				// Column1
				// 
				this->Column1->HeaderText = L"Id";
				this->Column1->MinimumWidth = 6;
				this->Column1->Name = L"Column1";
				this->Column1->Visible = false;
				this->Column1->Width = 50;
				// 
				// Column2
				// 
				this->Column2->HeaderText = L"Nombre";
				this->Column2->MinimumWidth = 6;
				this->Column2->Name = L"Column2";
				this->Column2->Width = 90;
				// 
				// Column3
				// 
				this->Column3->HeaderText = L"Email";
				this->Column3->MinimumWidth = 6;
				this->Column3->Name = L"Column3";
				this->Column3->Width = 145;
				// 
				// Column4
				// 
				this->Column4->HeaderText = L"Contraseña";
				this->Column4->MinimumWidth = 6;
				this->Column4->Name = L"Column4";
				this->Column4->Width = 125;
				// 
				// Column5
				// 
				this->Column5->HeaderText = L"Último Acceso";
				this->Column5->Name = L"Column5";
				this->Column5->Width = 125;
				// 
				// Column6
				// 
				this->Column6->HeaderText = L"Estado";
				this->Column6->MinimumWidth = 6;
				this->Column6->Name = L"Column6";
				this->Column6->Width = 90;
				// 
				// Column7
				// 
				this->Column7->HeaderText = L"Rol";
				this->Column7->Name = L"Column7";
				this->Column7->Width = 125;
				// 
				// groupBox1
				// 
				this->groupBox1->Controls->Add(this->comboBox1);
				this->groupBox1->Controls->Add(this->btnMostrarTodos);
				this->groupBox1->Controls->Add(this->btnBuscar);
				this->groupBox1->Controls->Add(this->label2);
				this->groupBox1->Controls->Add(this->textBox1);
				this->groupBox1->Controls->Add(this->label1);
				this->groupBox1->Location = System::Drawing::Point(11, 11);
				this->groupBox1->Margin = System::Windows::Forms::Padding(2);
				this->groupBox1->Name = L"groupBox1";
				this->groupBox1->Padding = System::Windows::Forms::Padding(2);
				this->groupBox1->Size = System::Drawing::Size(804, 101);
				this->groupBox1->TabIndex = 11;
				this->groupBox1->TabStop = false;
				this->groupBox1->Text = L"Criterios de Búsqueda";
				// 
				// comboBox1
				// 
				this->comboBox1->FormattingEnabled = true;
				this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Habilitado", L"Deshabilitado" });
				this->comboBox1->Location = System::Drawing::Point(326, 50);
				this->comboBox1->Name = L"comboBox1";
				this->comboBox1->Size = System::Drawing::Size(128, 21);
				this->comboBox1->TabIndex = 17;
				// 
				// btnBuscar
				// 
				this->btnBuscar->Location = System::Drawing::Point(493, 50);
				this->btnBuscar->Margin = System::Windows::Forms::Padding(2);
				this->btnBuscar->Name = L"btnBuscar";
				this->btnBuscar->Size = System::Drawing::Size(56, 19);
				this->btnBuscar->TabIndex = 4;
				this->btnBuscar->Text = L"Buscar";
				this->btnBuscar->UseVisualStyleBackColor = true;
				this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantUsuarios::btnBuscar_Click);
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Location = System::Drawing::Point(278, 53);
				this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(43, 13);
				this->label2->TabIndex = 2;
				this->label2->Text = L"Estado:";
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(86, 50);
				this->textBox1->Margin = System::Windows::Forms::Padding(2);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(128, 20);
				this->textBox1->TabIndex = 1;
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(26, 52);
				this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(50, 13);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Nombre :";
				// 
				// frmMantUsuarios
				// 
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
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				this->groupBox1->ResumeLayout(false);
				this->groupBox1->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion
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
		this->dataGridView1->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
		this->dataGridView1->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		// AGREGAR ESTAS LÍNEAS AL FINAL:
		this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill; // Estira las columnas
		this->dataGridView1->AutoGenerateColumns = false;
		this->dataGridView1->AllowUserToAddRows = false;
	}

		private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e){
			// Limpiar el DataGridView antes de mostrar todos los usuarios
			this->dataGridView1->Rows->Clear();
			List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
			if (comboBox1->Text == "Habilitado") {
				listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();
			}
			else if(comboBox1->Text == "Deshabilitado") {
				listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados();
			}
			else {
				MessageBox::Show("Por favor, seleccione un estado para mostrar todos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			mostrarGrilla(listaUsuarios);

		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e){
			frmNuevoUsuario^ nuevoUsuarioForm = gcnew frmNuevoUsuario(this->usuarioController);
			nuevoUsuarioForm->ShowDialog();
		}

		private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ nombreUsuario = textBox1->Text;
			String^ estadoTexto = comboBox1->Text;

			Nullable<bool> estadoUsuario;

			if (estadoTexto == "Habilitado") {
				estadoUsuario = true;
			}
			else if (estadoTexto == "Deshabilitado") {
				estadoUsuario = false;
			}
		
			List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
			if (nombreUsuario != "") {
				listaUsuarios = this->usuarioController->obtenerUsuarioPorNombreEstado(nombreUsuario, estadoUsuario);
			}
			mostrarGrilla(listaUsuarios);
		}

		private: System::Void btnCambiarEstado_Click(System::Object^ sender, System::EventArgs^ e) {
			// Verificar si se ha seleccionado una fila en el DataGridView
			if (this->dataGridView1->SelectedRows->Count > 0)
			{
				int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
				int idUsuario = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

				Usuario^ usuarioSeleccionado = this->usuarioController->obtenerUsuarioPorId(idUsuario);
				List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();

				// Preguntar al usuario si est� seguro de eliminar el registro
				System::Windows::Forms::DialogResult resultado = MessageBox::Show("¿Está seguro de que desea cambiar el estado del registro seleccionado?",
					"Confirmación de cambio de estado", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
			
				if (resultado == System::Windows::Forms::DialogResult::No)
				{
					return; // Salir del evento si el usuario cancela
				}
			
				this->usuarioController->cambiarEstadoUsuario(idUsuario);
			
				(usuarioSeleccionado->GetEstadoCuenta()) ? listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados() :
					listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();

				mostrarGrilla(listaUsuarios);
			}
			else
			{
				MessageBox::Show("Por favor, seleccione un usuario para habilitar/deshabilitar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}


		private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
			// Verificar si se ha seleccionado una fila en el DataGridView
			if (this->dataGridView1->SelectedRows->Count > 0)
			{
				int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
				int idUsuario = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value);

				Usuario^ usuarioSeleccionado = this->usuarioController->obtenerUsuarioPorId(idUsuario);
				if (usuarioSeleccionado == nullptr)
				{
					MessageBox::Show("No se encontró el usuario seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				if (usuarioSeleccionado->GetEstadoCuenta() == false) {
					MessageBox::Show("No se puede editar a un usuario deshabilitado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				// Crear una nueva instancia del formulario de nuevo usuario
				// y mostrarlo como un formulario hijo dentro del contenedor MDI
				frmEditarUsuario^ ventanaEditarUsuario = gcnew frmEditarUsuario(this->usuarioController, usuarioSeleccionado, this->rolController);
				ventanaEditarUsuario->ShowDialog();
				// Llamar al m�todo para cargar la lista de operadores nuevamente
				List<Usuario^>^ listaUsuarios = gcnew List<Usuario^>();
				if (usuarioSeleccionado->GetEstadoCuenta()) {
					listaUsuarios = this->usuarioController->obtenerUsuariosHabilitados();
				}
				else {
					listaUsuarios = this->usuarioController->obtenerUsuariosDeshabilitados();
				}
				mostrarGrilla(listaUsuarios);
			}
			else
			{
				MessageBox::Show("Por favor, seleccione un usuario para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	};
	}
