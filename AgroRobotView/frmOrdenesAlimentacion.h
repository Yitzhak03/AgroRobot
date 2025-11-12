#pragma once

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
	/// Resumen de frmOrdenesAlimentacion
	/// </summary>
	public ref class frmOrdenesAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmOrdenesAlimentacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->almacenController = gcnew AlmacenController();
			aplicarEstilo();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmOrdenesAlimentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: AlmacenController^ almacenController;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;

	private: void aplicarEstilo() {

		this->BackColor = System::Drawing::Color::FromArgb(238, 245, 233); 
		this->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Regular);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->MaximizeBox = false;
		this->StartPosition = FormStartPosition::CenterScreen;

		this->groupBox1->BackColor = System::Drawing::Color::White;
		this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(30, 60, 30);
		this->groupBox1->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 10, FontStyle::Bold);
		this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;

		this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
		this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(200, 225, 200);
		this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;

		this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(67, 160, 71); 
		this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
		this->dataGridView1->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 10, FontStyle::Bold);
		this->dataGridView1->EnableHeadersVisualStyles = false;

		this->dataGridView1->DefaultCellStyle->BackColor = System::Drawing::Color::White;
		this->dataGridView1->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(30, 60, 30);
		this->dataGridView1->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(180, 220, 180); 
		this->dataGridView1->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::Black;
		this->dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Regular);

		this->dataGridView1->RowHeadersVisible = false;
		this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
		this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView1->ReadOnly = true;

		this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
		this->dataGridView1->RowTemplate->Height = 28;
		this->dataGridView1->ClearSelection();
	}

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->Location = System::Drawing::Point(16, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(896, 250);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Orden";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Visible = false;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ID Dieta";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Robot";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Fecha";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Ruta";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Prioridad";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(26, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(929, 295);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Órdenes pendientes:";
			// 
			// frmOrdenesAlimentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 489);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmOrdenesAlimentacion";
			this->Text = L"Reportes - Órdenes de alimentación";
			this->Load += gcnew System::EventHandler(this, &frmOrdenesAlimentacion::frmOrdenesAlimentacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmOrdenesAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		this->mostrarGrilla(this->almacenController->listarOrdenes());
	}

	public: void mostrarGrilla(List<OrdenDistribucion^>^ listaOrdenes)
	{
		this->dataGridView1->Rows->Clear();

		for (int i = 0; i < listaOrdenes->Count; i++)
		{
			OrdenDistribucion^ orden = listaOrdenes[i];
			array<String^>^ filaGrilla = gcnew array<String^>(6);
			filaGrilla[0] = Convert::ToString(orden->Id);
			filaGrilla[1] = Convert::ToString(orden->IdDieta);
			filaGrilla[2] = orden->RobotAsignado;
			filaGrilla[3] = orden->FechaHoraEntrega;
			filaGrilla[4] = orden->Ruta;
			filaGrilla[5] = orden->Prioridad;

			this->dataGridView1->Rows->Add(filaGrilla);
		}
	}
	};
}
