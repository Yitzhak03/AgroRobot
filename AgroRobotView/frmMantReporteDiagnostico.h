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
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Resumen de frmMantReporteDiagnostico
	/// </summary>
	public ref class frmMantReporteDiagnostico : public System::Windows::Forms::Form
	{
	public:
		frmMantReporteDiagnostico(void)
		{
			InitializeComponent();
			this->reporteController = gcnew ReporteDiagnosticoController();
			this->pdfExportController = gcnew PdfExportServiceController();
			this->reporteActual = nullptr;

			// Configuración inicial
			ConfigurarControlesIniciales();
			ConfigurarCharts(); // Llamar después de InitializeComponent
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantReporteDiagnostico()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Controles existentes
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::GroupBox^ groupBox2;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TabControl^ tabControl1;
		System::Windows::Forms::TabPage^ tabPage1;
		System::Windows::Forms::TabPage^ tabPage2;
		System::Windows::Forms::TabPage^ tabPage3;
		System::Windows::Forms::GroupBox^ groupBox3;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button2;

		// Nuevos controles
		ReporteDiagnosticoController^ reporteController;
		PdfExportServiceController^ pdfExportController;
		ReporteDiagnosticoResult^ reporteActual;
		Chart^ chartTipoAnalisis;
		Chart^ chartEstadoSalud;
		System::Windows::Forms::DataGridView^ dataGridEstadisticas;
		System::Windows::Forms::DataGridView^ dataGridDetalle;
		System::Windows::Forms::ComboBox^ comboAnio;
		System::Windows::Forms::ComboBox^ comboMes;
		System::Windows::Forms::RadioButton^ radioMensual;
		System::Windows::Forms::RadioButton^ radioRango;

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
			this->chartTipoAnalisis = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartEstadoSalud = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioMensual = (gcnew System::Windows::Forms::RadioButton());
			this->radioRango = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->BeginInit();
			this->comboAnio = (gcnew System::Windows::Forms::ComboBox());
			this->comboMes = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridEstadisticas = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioMensual);
			this->groupBox1->Controls->Add(this->radioRango);
			this->groupBox1->Controls->Add(this->comboAnio);
			this->groupBox1->Controls->Add(this->comboMes);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker2);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Location = System::Drawing::Point(35, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(408, 121);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de búsqueda";
			// 
			// radioMensual
			// 
			this->radioMensual->AutoSize = true;
			this->radioMensual->Location = System::Drawing::Point(24, 60);
			this->radioMensual->Name = L"radioMensual";
			this->radioMensual->Size = System::Drawing::Size(65, 17);
			this->radioMensual->TabIndex = 14;
			this->radioMensual->TabStop = true;
			this->radioMensual->Text = L"Mensual";
			this->radioMensual->UseVisualStyleBackColor = true;
			this->radioMensual->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioMensual_CheckedChanged);
			// 
			// radioRango
			// 
			this->radioRango->AutoSize = true;
			this->radioRango->Location = System::Drawing::Point(24, 35);
			this->radioRango->Name = L"radioRango";
			this->radioRango->Size = System::Drawing::Size(57, 17);
			this->radioRango->TabIndex = 15;
			this->radioRango->Text = L"Rango";
			this->radioRango->UseVisualStyleBackColor = true;
			this->radioRango->CheckedChanged += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::radioRango_CheckedChanged);
			// 
			// comboAnio
			// 
			this->comboAnio->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboAnio->FormattingEnabled = true;
			this->comboAnio->Location = System::Drawing::Point(100, 58);
			this->comboAnio->Name = L"comboAnio";
			this->comboAnio->Size = System::Drawing::Size(70, 21);
			this->comboAnio->TabIndex = 16;
			// 
			// comboMes
			// 
			this->comboMes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboMes->FormattingEnabled = true;
			this->comboMes->Location = System::Drawing::Point(180, 58);
			this->comboMes->Name = L"comboMes";
			this->comboMes->Size = System::Drawing::Size(100, 21);
			this->comboMes->TabIndex = 17;
			// 
			// chartTipoAnalisis
			// 
			this->chartTipoAnalisis->Location = System::Drawing::Point(10, 10);
			this->chartTipoAnalisis->Name = L"chartTipoAnalisis";
			this->chartTipoAnalisis->Size = System::Drawing::Size(380, 140);
			this->chartTipoAnalisis->TabIndex = 0;
			this->chartTipoAnalisis->Text = L"Tipos de Análisis";
			// 
			// chartEstadoSalud
			// 
			this->chartEstadoSalud->Location = System::Drawing::Point(10, 160);
			this->chartEstadoSalud->Name = L"chartEstadoSalud";
			this->chartEstadoSalud->Size = System::Drawing::Size(380, 130);
			this->chartEstadoSalud->TabIndex = 1;
			this->chartEstadoSalud->Text = L"Estados de Salud";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartTipoAnalisis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstadoSalud))->EndInit();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(206, 85);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 23);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Limpiar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button3_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(100, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(227, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"a";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Rango:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(257, 33);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(121, 20);
			this->dateTimePicker2->TabIndex = 6;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(87, 33);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(121, 20);
			this->dateTimePicker1->TabIndex = 2;
			this->dateTimePicker1->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Location = System::Drawing::Point(35, 172);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(408, 116);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Resumen Ejecutivo";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(327, 75);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(56, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(230, 75);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(56, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 75);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(58, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(324, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Heces";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(227, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Sangre";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(127, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 26);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Animales\r\nÚnicos";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(27, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(55, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 37);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 26);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Total\r\nMuestras";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(35, 317);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(408, 329);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chartTipoAnalisis);
			this->tabPage1->Controls->Add(this->chartEstadoSalud);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(400, 303);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Gráficos";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridEstadisticas);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(400, 217);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Estadísticas";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridEstadisticas
			// 
			this->dataGridEstadisticas->AllowUserToAddRows = false;
			this->dataGridEstadisticas->AllowUserToDeleteRows = false;
			this->dataGridEstadisticas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridEstadisticas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridEstadisticas->Name = L"dataGridEstadisticas";
			this->dataGridEstadisticas->ReadOnly = true;
			this->dataGridEstadisticas->Size = System::Drawing::Size(380, 200);
			this->dataGridEstadisticas->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridDetalle);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(400, 217);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Detalle";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridDetalle
			// 
			this->dataGridDetalle->AllowUserToAddRows = false;
			this->dataGridDetalle->AllowUserToDeleteRows = false;
			this->dataGridDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridDetalle->Name = L"dataGridDetalle";
			this->dataGridDetalle->ReadOnly = true;
			this->dataGridDetalle->Size = System::Drawing::Size(380, 200);
			this->dataGridDetalle->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Location = System::Drawing::Point(35, 664);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(408, 73);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Exportar a:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(298, 29);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 23);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(172, 29);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 23);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Excel";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button4_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(40, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"PDF";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::button2_Click);
			// 
			// frmMantReporteDiagnostico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(469, 749);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantReporteDiagnostico";
			this->Text = L"Reporte de Diagnóstico Médico";
			this->Load += gcnew System::EventHandler(this, &frmMantReporteDiagnostico::frmMantReporteDiagnostico_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridEstadisticas))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridDetalle))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void frmMantReporteDiagnostico_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			GenerarReporte();
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			LimpiarControles();
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			ExportarPDF();
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			ExportarExcel();
		}

		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void radioMensual_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			HabilitarControlesMensual();
		}

		System::Void radioRango_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			HabilitarControlesRango();
		}

	private:
		void ConfigurarControlesIniciales() {
			// Configurar años (últimos 5 años)
			int añoActual = DateTime::Now.Year;
			for (int i = añoActual; i >= añoActual - 5; i--) {
				comboAnio->Items->Add(i.ToString());
			}
			comboAnio->SelectedIndex = 0;

			// Configurar meses
			array<String^>^ meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
									"Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
			comboMes->Items->AddRange(meses);
			comboMes->SelectedIndex = DateTime::Now.Month - 1;

			// Configurar fechas por defecto
			dateTimePicker1->Value = DateTime::Today.AddMonths(-1);
			dateTimePicker2->Value = DateTime::Today;

			HabilitarControlesMensual();
		}

		void HabilitarControlesMensual() {
			comboAnio->Enabled = true;
			comboMes->Enabled = true;
			dateTimePicker1->Enabled = false;
			dateTimePicker2->Enabled = false;
		}

		void HabilitarControlesRango() {
			comboAnio->Enabled = false;
			comboMes->Enabled = false;
			dateTimePicker1->Enabled = true;
			dateTimePicker2->Enabled = true;
		}

		void GenerarReporte() {
			try {
				if (radioMensual->Checked) {
					int año = Convert::ToInt32(comboAnio->SelectedItem);
					int mes = comboMes->SelectedIndex + 1;
					reporteActual = reporteController->GenerarReporteMensual(año, mes);
				}
				else {
					String^ fechaInicio = dateTimePicker1->Value.ToString("yyyy-MM-dd");
					String^ fechaFin = dateTimePicker2->Value.ToString("yyyy-MM-dd");
					reporteActual = reporteController->GenerarReportePorRangoFechas(fechaInicio, fechaFin);
				}

				ActualizarResumen();
				ActualizarGraficos();
				ActualizarEstadisticas();
				ActualizarDetalle();

			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al generar reporte: " + ex->Message, "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void ActualizarResumen() {
			if (reporteActual == nullptr) return;

			textBox2->Text = reporteActual->TotalMuestras.ToString();
			textBox1->Text = reporteActual->TotalAnimales.ToString();

			// Calcular muestras por tipo
			int sangre = 0, heces = 0;
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				if (stat->Categoria == "Sangre") sangre = stat->Cantidad;
				else if (stat->Categoria == "Heces") heces = stat->Cantidad;
			}

			textBox3->Text = sangre.ToString();
			textBox4->Text = heces.ToString();
		}

		void ActualizarGraficos() {
			if (reporteActual == nullptr) return;

			// Limpiar gráficos anteriores
			chartTipoAnalisis->Series->Clear();
			chartEstadoSalud->Series->Clear();

			// Configurar series si no existen
			if (chartTipoAnalisis->Series->Count == 0) {
				Series^ series1 = gcnew Series("Tipos");
				series1->ChartType = SeriesChartType::Column;
				series1->IsValueShownAsLabel = true;
				chartTipoAnalisis->Series->Add(series1);
			}

			if (chartEstadoSalud->Series->Count == 0) {
				Series^ series2 = gcnew Series("Estados");
				series2->ChartType = SeriesChartType::Pie;
				series2->IsValueShownAsLabel = true;
				chartEstadoSalud->Series->Add(series2);
			}

			// Actualizar gráfico de tipos de análisis
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				chartTipoAnalisis->Series["Tipos"]->Points->AddXY(stat->Categoria, stat->Cantidad);
			}

			// Actualizar gráfico de estados de salud
			for each (auto stat in reporteActual->PorEstadoSalud) {
				chartEstadoSalud->Series["Estados"]->Points->AddXY(stat->Categoria, stat->Cantidad);
			}
		}

		void ActualizarEstadisticas() {
			if (reporteActual == nullptr) return;

			// Configurar DataGridView de estadísticas
			dataGridEstadisticas->Rows->Clear();
			dataGridEstadisticas->Columns->Clear();

			// Agregar columnas
			dataGridEstadisticas->Columns->Add("Categoria", "Categoría");
			dataGridEstadisticas->Columns->Add("Cantidad", "Cantidad");
			dataGridEstadisticas->Columns->Add("Porcentaje", "Porcentaje");

			// Agregar datos de tipos de análisis (sin título redundante)
			for each (auto stat in reporteActual->PorTipoAnalisis) {
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
			}

			// Agregar datos de estados de salud (sin título redundante)
			for each (auto stat in reporteActual->PorEstadoSalud) {
				dataGridEstadisticas->Rows->Add(stat->Categoria, stat->Cantidad, stat->Porcentaje.ToString("F1") + "%");
			}

			// Configurar para que ocupe todo el espacio disponible
			dataGridEstadisticas->Dock = DockStyle::Fill;
			dataGridEstadisticas->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// Hacer que la primera columna sea más ancha para los textos largos
			if (dataGridEstadisticas->Columns->Count > 0) {
				dataGridEstadisticas->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			}

		}


		void ActualizarDetalle() {
			if (reporteActual == nullptr) return;

			dataGridDetalle->Rows->Clear();
			dataGridDetalle->Columns->Clear();

			// Agregar columnas con mejor configuración
			dataGridDetalle->Columns->Add("Numero", "N°");
			dataGridDetalle->Columns->Add("Detalle", "Detalle de Muestra");

			// Configurar para que ocupe todo el espacio disponible
			dataGridDetalle->Dock = DockStyle::Fill;
			dataGridDetalle->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

			// Agregar datos
			for (int i = 0; i < reporteActual->MuestrasResumen->Count; i++) {
				dataGridDetalle->Rows->Add((i + 1).ToString(), reporteActual->MuestrasResumen[i]);
			}
		}

		void LimpiarControles() {
			textBox2->Text = "";
			textBox1->Text = "";
			textBox3->Text = "";
			textBox4->Text = "";

			chartTipoAnalisis->Series->Clear();
			chartEstadoSalud->Series->Clear();

			dataGridEstadisticas->Rows->Clear();
			dataGridDetalle->Rows->Clear();

			reporteActual = nullptr;
		}

		void ExportarPDF() {
			if (reporteActual == nullptr) {
				MessageBox::Show("No hay datos para exportar. Genere un reporte primero.",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivos PDF|*.pdf";
			saveDialog->Title = "Guardar reporte como PDF";
			saveDialog->FileName = "Reporte_Diagnostico_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".pdf";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteDiagnosticoPDF(reporteActual, saveDialog->FileName);
				if (exito) {
					MessageBox::Show("Reporte exportado exitosamente a PDF.", "Éxito",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al exportar el reporte a PDF.", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		void ExportarExcel() {
			if (reporteActual == nullptr) {
				MessageBox::Show("No hay datos para exportar. Genere un reporte primero.",
					"Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Archivos CSV|*.csv";
			saveDialog->Title = "Guardar reporte como Excel";
			saveDialog->FileName = "Reporte_Diagnostico_" + DateTime::Now.ToString("yyyyMMdd_HHmm") + ".csv";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				bool exito = pdfExportController->ExportarReporteDiagnosticoExcel(reporteActual, saveDialog->FileName);
				if (exito) {
					MessageBox::Show("Reporte exportado exitosamente a Excel.", "Éxito",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Error al exportar el reporte a Excel.", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
    
		} // Fin de ExportarExcel()

		
		private:
			void ConfigurarCharts() {
				// Configurar chartTipoAnalisis
				if (chartTipoAnalisis != nullptr) {
					chartTipoAnalisis->ChartAreas->Add(gcnew ChartArea());
					chartTipoAnalisis->ChartAreas[0]->AxisX->Title = "Tipo de Análisis";
					chartTipoAnalisis->ChartAreas[0]->AxisY->Title = "Cantidad";
					chartTipoAnalisis->Series->Add(gcnew Series());
					chartTipoAnalisis->Series[0]->ChartType = SeriesChartType::Column;
					chartTipoAnalisis->Series[0]->Name = "Tipos";
					chartTipoAnalisis->Series[0]->IsValueShownAsLabel = true;
					chartTipoAnalisis->Titles->Add("Tipos de Análisis");
				}

				// Configurar chartEstadoSalud
				if (chartEstadoSalud != nullptr) {
					chartEstadoSalud->ChartAreas->Add(gcnew ChartArea());
					chartEstadoSalud->Series->Add(gcnew Series());
					chartEstadoSalud->Series[0]->ChartType = SeriesChartType::Pie;
					chartEstadoSalud->Series[0]->Name = "Estados";
					chartEstadoSalud->Series[0]->IsValueShownAsLabel = true;
					chartEstadoSalud->Titles->Add("Estados de Salud");
				}
			}
			

    }; // Fin de la clase frmMantReporteDiagnostico

    } // Fin del namespace AgroRobotView