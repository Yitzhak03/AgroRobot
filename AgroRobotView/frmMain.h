#pragma once
#include "frmMenu.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; // Para usar List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Referencias a los otros proyectos
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form {
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMain()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtUsuario;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtContrasenha;

	private: System::Windows::Forms::Button^ button2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtContrasenha = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(148, 188);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Iniciar sesión";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Contraseña:";
			// 
			// txtUsuario
			// 
			this->txtUsuario->Location = System::Drawing::Point(117, 88);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(176, 20);
			this->txtUsuario->TabIndex = 6;
			this->txtUsuario->Text = "Becquer";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(48, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Usuario:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(112, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 25);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Bienvenido!";
			// 
			// txtContrasenha
			// 
			this->txtContrasenha->Location = System::Drawing::Point(117, 132);
			this->txtContrasenha->Name = L"txtContrasenha";
			this->txtContrasenha->Size = System::Drawing::Size(176, 20);
			this->txtContrasenha->TabIndex = 11;
			this->txtContrasenha->UseSystemPasswordChar = true;
			this->txtContrasenha->Text = "123456";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button2->Location = System::Drawing::Point(300, 130);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 23);
			this->button2->TabIndex = 12;
			this->button2->Text = L"👁";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmMain::button2_Click);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(358, 244);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->txtContrasenha);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//==============================================================================
	//==========================INICIAR SESION======================================
	//==============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ usuario = txtUsuario->Text;
		String^ contrasenha = txtContrasenha->Text;
		
		// Validar campos vacíos
		if (String::IsNullOrEmpty(usuario) || String::IsNullOrEmpty(contrasenha)) {
			MessageBox::Show("Ingrese usuario y contraseña.", "Login", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		UsuarioController^ ctrl = gcnew UsuarioController();
		List<Usuario^>^ lista = ctrl->obtenerTodosUsuarios();
		
		for each (Usuario ^ u in lista) {
			// comparar nombre de usuario sin distinguir mayúsculas/minúsculas,
			// pero la contraseña sí (por convención)
			if (String::Compare(u->Nombre, usuario, false) == 0 && u->Contrasenha->Equals(contrasenha)) {
				// Autenticado
				MessageBox::Show("Acceso correcto. Bienvenido " + u->Nombre, "Login", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Aquí puedes guardar el usuario actual en una variable global/static o abrir el formulario principal
				this->Hide(); // Ocultar el formulario de login
				frmMenu^ menu = gcnew frmMenu(u); // Pasar el usuario autenticado
				menu->ShowDialog(); // Mostrar el formulario del menú principal
				this->Close(); // Cerrar el formulario de login al volver del menú
				return;
			}
		}
		// No encontrado / credenciales inválidas
		MessageBox::Show("Usuario o contraseña incorrectos.", "Login", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	//==============================================================================
	//====================================👁========================================
	//==============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (txtContrasenha->UseSystemPasswordChar) {
			txtContrasenha->UseSystemPasswordChar = false; // Mostrar contraseña
		}
		else {
			txtContrasenha->UseSystemPasswordChar = true; // Ocultar contraseña
		}
	}
};
}
