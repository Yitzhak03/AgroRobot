#pragma once
#include "frmMantUsuarios.h"
#include "frmMantInsumo.h"
#include "frmMantReportes.h"
#include "frmMantDietas.h"
#include "frmMantAnimales.h"
#include "frmOrdenesAlimentacion.h"
#include "frmMantDiagnostico.h"
#include "frmMantHeces.h"
#include "frmMantSangre.h"
#include "frmMantRoles.h"
#include "frmMantAlmacen.h"

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel; // Referencia al proyecto AgroRobotModel
	/// <summary>
	/// Resumen de frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form {
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		// Nuevo constructor para recibir el usuario autenticado
		frmMenu(Usuario^ usuario)
		{
			this->usuario = usuario;
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMenu()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ admnistracionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ diagnosticoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ planDeAlimentacionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ almacenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ volverToolStripMenuItem;
	private: Usuario^ usuario;
	private: System::Windows::Forms::ToolStripMenuItem^ registroInsumosGeneralToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gestiónDeReportesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registroDeDietasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registroDeAnimalesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ géstionDeDiagnosticosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gestiónDeMuestrasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ muestraDeHecesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ muestraDeSangreToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoDeUsuariosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoDeRolesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ registroGeneralDeAlmacenesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gestiónDeOrdenesDeAlimentaciónToolStripMenuItem;

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMenu::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->admnistracionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientoDeUsuariosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientoDeRolesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diagnosticoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->géstionDeDiagnosticosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gestiónDeMuestrasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->muestraDeHecesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->muestraDeSangreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->planDeAlimentacionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroDeDietasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroDeAnimalesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->almacenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroInsumosGeneralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroGeneralDeAlmacenesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gestiónDeReportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->volverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(118)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Pixel));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(35, 35);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6)
			{
				this->admnistracionToolStripMenuItem,
					this->diagnosticoToolStripMenuItem, this->planDeAlimentacionToolStripMenuItem, this->almacenToolStripMenuItem, this->reportesToolStripMenuItem,
					this->volverToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 10, 0, 10);
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->menuStrip1->Size = System::Drawing::Size(1180, 75);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// admnistracionToolStripMenuItem
			// 
			this->admnistracionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->mantenimientoDeUsuariosToolStripMenuItem,
					this->mantenimientoDeRolesToolStripMenuItem
			});
			this->admnistracionToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->admnistracionToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"admnistracionToolStripMenuItem.Image")));
			this->admnistracionToolStripMenuItem->Name = L"admnistracionToolStripMenuItem";
			this->admnistracionToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 8, 15, 8);
			this->admnistracionToolStripMenuItem->Size = System::Drawing::Size(210, 55);
			this->admnistracionToolStripMenuItem->Text = L"Administración";
			// 
			// mantenimientoDeUsuariosToolStripMenuItem
			// 
			this->mantenimientoDeUsuariosToolStripMenuItem->Name = L"mantenimientoDeUsuariosToolStripMenuItem";
			this->mantenimientoDeUsuariosToolStripMenuItem->Size = System::Drawing::Size(319, 30);
			this->mantenimientoDeUsuariosToolStripMenuItem->Text = L"Mantenimiento de Usuarios";
			this->mantenimientoDeUsuariosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::mantenimientoDeUsuariosToolStripMenuItem_Click);
			// 
			// mantenimientoDeRolesToolStripMenuItem
			// 
			this->mantenimientoDeRolesToolStripMenuItem->Name = L"mantenimientoDeRolesToolStripMenuItem";
			this->mantenimientoDeRolesToolStripMenuItem->Size = System::Drawing::Size(319, 30);
			this->mantenimientoDeRolesToolStripMenuItem->Text = L"Mantenimiento de Roles";
			this->mantenimientoDeRolesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::mantenimientoDeRolesToolStripMenuItem_Click);
			// 
			// diagnosticoToolStripMenuItem
			// 
			this->diagnosticoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->géstionDeDiagnosticosToolStripMenuItem,
					this->gestiónDeMuestrasToolStripMenuItem
			});
			this->diagnosticoToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->diagnosticoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"diagnosticoToolStripMenuItem.Image")));
			this->diagnosticoToolStripMenuItem->Name = L"diagnosticoToolStripMenuItem";
			this->diagnosticoToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->diagnosticoToolStripMenuItem->Size = System::Drawing::Size(182, 55);
			this->diagnosticoToolStripMenuItem->Text = L"Diagnóstico";
			this->diagnosticoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::diagnosticoToolStripMenuItem_Click);
			// 
			// géstionDeDiagnosticosToolStripMenuItem
			// 
			this->géstionDeDiagnosticosToolStripMenuItem->Name = L"géstionDeDiagnosticosToolStripMenuItem";
			this->géstionDeDiagnosticosToolStripMenuItem->Size = System::Drawing::Size(289, 30);
			this->géstionDeDiagnosticosToolStripMenuItem->Text = L"Gestión de Diagnosticos";
			this->géstionDeDiagnosticosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::géstionDeDiagnosticosToolStripMenuItem_Click);
			// 
			// gestiónDeMuestrasToolStripMenuItem
			// 
			this->gestiónDeMuestrasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->muestraDeHecesToolStripMenuItem,
					this->muestraDeSangreToolStripMenuItem
			});
			this->gestiónDeMuestrasToolStripMenuItem->Name = L"gestiónDeMuestrasToolStripMenuItem";
			this->gestiónDeMuestrasToolStripMenuItem->Size = System::Drawing::Size(289, 30);
			this->gestiónDeMuestrasToolStripMenuItem->Text = L"Gestión de Muestras";
			this->gestiónDeMuestrasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::gestiónDeMuestrasToolStripMenuItem_Click);
			// 
			// muestraDeHecesToolStripMenuItem
			// 
			this->muestraDeHecesToolStripMenuItem->Name = L"muestraDeHecesToolStripMenuItem";
			this->muestraDeHecesToolStripMenuItem->Size = System::Drawing::Size(244, 30);
			this->muestraDeHecesToolStripMenuItem->Text = L"Muestra de Heces";
			this->muestraDeHecesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::muestraDeHecesToolStripMenuItem_Click);
			// 
			// muestraDeSangreToolStripMenuItem
			// 
			this->muestraDeSangreToolStripMenuItem->Name = L"muestraDeSangreToolStripMenuItem";
			this->muestraDeSangreToolStripMenuItem->Size = System::Drawing::Size(244, 30);
			this->muestraDeSangreToolStripMenuItem->Text = L"Muestra de Sangre";
			this->muestraDeSangreToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::muestraDeSangreToolStripMenuItem_Click);
			// 
			// planDeAlimentacionToolStripMenuItem
			// 
			this->planDeAlimentacionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->registroDeDietasToolStripMenuItem,
					this->registroDeAnimalesToolStripMenuItem
			});
			this->planDeAlimentacionToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->planDeAlimentacionToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"planDeAlimentacionToolStripMenuItem.Image")));
			this->planDeAlimentacionToolStripMenuItem->Name = L"planDeAlimentacionToolStripMenuItem";
			this->planDeAlimentacionToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->planDeAlimentacionToolStripMenuItem->Size = System::Drawing::Size(259, 55);
			this->planDeAlimentacionToolStripMenuItem->Text = L"Plan de alimentación";
			// 
			// registroDeDietasToolStripMenuItem
			// 
			this->registroDeDietasToolStripMenuItem->Name = L"registroDeDietasToolStripMenuItem";
			this->registroDeDietasToolStripMenuItem->Size = System::Drawing::Size(261, 30);
			this->registroDeDietasToolStripMenuItem->Text = L"Registro de dietas";
			this->registroDeDietasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::registroDeDietasToolStripMenuItem_Click);
			// 
			// registroDeAnimalesToolStripMenuItem
			// 
			this->registroDeAnimalesToolStripMenuItem->Name = L"registroDeAnimalesToolStripMenuItem";
			this->registroDeAnimalesToolStripMenuItem->Size = System::Drawing::Size(261, 30);
			this->registroDeAnimalesToolStripMenuItem->Text = L"Registro de animales";
			this->registroDeAnimalesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::registroDeAnimalesToolStripMenuItem_Click);
			// 
			// almacenToolStripMenuItem
			// 
			this->almacenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->registroInsumosGeneralToolStripMenuItem,
					this->registroGeneralDeAlmacenesToolStripMenuItem
			});
			this->almacenToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->almacenToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"almacenToolStripMenuItem.Image")));
			this->almacenToolStripMenuItem->Name = L"almacenToolStripMenuItem";
			this->almacenToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->almacenToolStripMenuItem->Size = System::Drawing::Size(155, 55);
			this->almacenToolStripMenuItem->Text = L"Almacén";
			// 
			// registroInsumosGeneralToolStripMenuItem
			// 
			this->registroInsumosGeneralToolStripMenuItem->Name = L"registroInsumosGeneralToolStripMenuItem";
			this->registroInsumosGeneralToolStripMenuItem->Size = System::Drawing::Size(349, 30);
			this->registroInsumosGeneralToolStripMenuItem->Text = L"Registro General de Insumos";
			this->registroInsumosGeneralToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::registroInsumosGeneralToolStripMenuItem_Click);
			// 
			// registroGeneralDeAlmacenesToolStripMenuItem
			// 
			this->registroGeneralDeAlmacenesToolStripMenuItem->Name = L"registroGeneralDeAlmacenesToolStripMenuItem";
			this->registroGeneralDeAlmacenesToolStripMenuItem->Size = System::Drawing::Size(349, 30);
			this->registroGeneralDeAlmacenesToolStripMenuItem->Text = L"Registro General de Almacenes";
			this->registroGeneralDeAlmacenesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::registroGeneralDeAlmacenesToolStripMenuItem_Click);
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->gestiónDeReportesToolStripMenuItem,
					this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem
			});
			this->reportesToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->reportesToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reportesToolStripMenuItem.Image")));
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->reportesToolStripMenuItem->Size = System::Drawing::Size(158, 55);
			this->reportesToolStripMenuItem->Text = L"Reportes";
			// 
			// gestiónDeReportesToolStripMenuItem
			// 
			this->gestiónDeReportesToolStripMenuItem->Name = L"gestiónDeReportesToolStripMenuItem";
			this->gestiónDeReportesToolStripMenuItem->Size = System::Drawing::Size(299, 30);
			this->gestiónDeReportesToolStripMenuItem->Text = L"Gestión de Reportes";
			this->gestiónDeReportesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::gestiónDeReportesToolStripMenuItem_Click);
			// 
			// gestiónDeOrdenesDeAlimentaciónToolStripMenuItem
			// 
			this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem->Name = L"gestiónDeOrdenesDeAlimentaciónToolStripMenuItem";
			this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem->Size = System::Drawing::Size(299, 30);
			this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem->Text = L"Ordenes de Alimentación";
			this->gestiónDeOrdenesDeAlimentaciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::ordenesDeAlimentaciónToolStripMenuItem_Click);
			// 
			// volverToolStripMenuItem
			// 
			this->volverToolStripMenuItem->ForeColor = System::Drawing::Color::Ivory;
			this->volverToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"volverToolStripMenuItem.Image")));
			this->volverToolStripMenuItem->Name = L"volverToolStripMenuItem";
			this->volverToolStripMenuItem->Padding = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->volverToolStripMenuItem->Size = System::Drawing::Size(135, 55);
			this->volverToolStripMenuItem->Text = L"Volver";
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1180, 642);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->Name = L"frmMenu";
			this->Text = L"Menú Principal";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmMenu::frmMenu_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//===============================================================================
		//==============================Administracion===================================
		//===============================================================================


	private: System::Void diagnosticoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
		   //===============================================================================
		   //==============================Registro Insumos General=========================
		   //===============================================================================
	private: System::Void registroInsumosGeneralToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantInsumo^ frm = gcnew frmMantInsumo();
		frm->MdiParent = this;
		frm->Show();
	}
	private: System::Void gestiónDeReportesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantReportes^ reportesForm = gcnew frmMantReportes();
		reportesForm->MdiParent = this;
		reportesForm->Show();
	}

	private: System::Void registroDeDietasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantDietas^ frm = gcnew frmMantDietas();
		frm->MdiParent = this;
		frm->Show();
	}

	private: System::Void registroDeAnimalesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantAnimales^ frm = gcnew frmMantAnimales();
		frm->MdiParent = this;
		frm->Show();
	}
	private: System::Void géstionDeDiagnosticosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantDiagnostico^ formMantDiagnostico = gcnew frmMantDiagnostico();
		formMantDiagnostico->MdiParent = this;
		formMantDiagnostico->Show();
	}
	private: System::Void gestiónDeMuestrasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void muestraDeHecesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantHeces^ formMantHeces = gcnew frmMantHeces();
		formMantHeces->MdiParent = this;
		formMantHeces->Show();
	}
	private: System::Void muestraDeSangreToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantSangre^ formMantSangre = gcnew frmMantSangre();
		formMantSangre->MdiParent = this;
		formMantSangre->Show();
	}

	private: System::Void ordenesDeAlimentaciónToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmOrdenesAlimentacion^ frm = gcnew frmOrdenesAlimentacion();
		frm->MdiParent = this;
		frm->Show();
	}

	private: System::Void registroGeneralDeAlmacenesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantAlmacen^ frm = gcnew frmMantAlmacen();
		frm->MdiParent = this;
		frm->Show();
	}


		   //===============================================================================
		   //=========================Módulo de Administracion==============================
		   //===============================================================================

		   /*vuelve invisible al botón Administración si no lo abre un usuario Administrador*/
	private: System::Void frmMenu_Load(System::Object^ sender, System::EventArgs^ e)
	{
		Rol^ rolUsuario = this->usuario->GetRol();
		this->admnistracionToolStripMenuItem->Visible = rolUsuario->GetPermisos()[0];
	}


	private: System::Void mantenimientoDeUsuariosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantUsuarios^ frm = gcnew frmMantUsuarios();
		frm->MdiParent = this;
		frm->Show();
	}

	private: System::Void mantenimientoDeRolesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantRoles^ ventanaRoles = gcnew frmMantRoles();
		ventanaRoles->MdiParent = this;
		ventanaRoles->Show();
	}
	};
}
