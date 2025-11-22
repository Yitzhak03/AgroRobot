#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // Necesario para exportar archivos
	using namespace System::Collections::Generic;

	// Referencias a tus proyectos
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmReporteInsumosXalmacen
	/// </summary>
	public ref class frmReporteInsumosXalmacen : public System::Windows::Forms::Form {
	public:
		frmReporteInsumosXalmacen(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmReporteInsumosXalmacen()
		{
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnExportar; // <--- BOTÓN NUEVO

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnExportar = (gcnew System::Windows::Forms::Button()); // Inicializar botón

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();

			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea2->AxisX->Title = L"Nombre del almacén";
			chartArea2->AxisX->TitleFont = (gcnew System::Drawing::Font(L"Noto Mono", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			chartArea2->AxisY->Title = L"Cantidad de insumos";
			chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Noto Mono", 8.25F, System::Drawing::FontStyle::Bold));
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(33, 98);
			this->chart1->Name = L"chart1";
			series2->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::TopBottom;
			series2->BackSecondaryColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			series2->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::NotSet;
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(146)));
			series2->IsVisibleInLegend = false;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(679, 393);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";

			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->label1->Location = System::Drawing::Point(28, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Insumos por almacén";

			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->label2->Location = System::Drawing::Point(30, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(258, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Conteo de insumos registrados en cada almacén";

			// 
			// btnExportar (CONFIGURACIÓN VISUAL)
			// 
			this->btnExportar->Location = System::Drawing::Point(532, 37); // Arriba a la derecha
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(180, 35);
			this->btnExportar->TabIndex = 3;
			this->btnExportar->Text = L"Exportar Reporte";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->BackColor = System::Drawing::Color::FromArgb(118, 222, 146); // Verde suave
			this->btnExportar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExportar->FlatAppearance->BorderSize = 0;
			this->btnExportar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnExportar->ForeColor = System::Drawing::Color::FromArgb(22, 53, 45);
			this->btnExportar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnExportar->Click += gcnew System::EventHandler(this, &frmReporteInsumosXalmacen::btnExportar_Click);

			// 
			// frmReporteInsumosXalmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(251)),
				static_cast<System::Int32>(static_cast<System::Byte>(248)));
			this->ClientSize = System::Drawing::Size(755, 529);
			this->Controls->Add(this->btnExportar); // Agregar botón
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"frmReporteInsumosXalmacen";
			this->Text = L"Insumos por almacén";
			this->Load += gcnew System::EventHandler(this, &frmReporteInsumosXalmacen::frmReporteInsumosXalmacen_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void frmReporteInsumosXalmacen_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Cargar datos en el gráfico
		ReporteInsumosXalmacenController^ reporteCtrl = gcnew ReporteInsumosXalmacenController();
		List<ReporteInsumosXalmacen^>^ reporte = reporteCtrl->generarReporte();

		this->chart1->Series["Series1"]->Points->Clear();
		for each (ReporteInsumosXalmacen ^ item in reporte) {
			this->chart1->Series["Series1"]->Points->AddXY(item->Nombre, item->CantInsumos);
		}
	}

		   // --- LÓGICA DE EXPORTACIÓN ---
	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// 1. Obtener datos (usando el mismo controller)
			ReporteInsumosXalmacenController^ reporteCtrl = gcnew ReporteInsumosXalmacenController();
			List<ReporteInsumosXalmacen^>^ datos = reporteCtrl->generarReporte();

			if (datos->Count == 0) {
				MessageBox::Show("No hay datos para exportar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			// 2. Diálogo de guardado
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Reporte de Texto|*.txt";
			saveDialog->Title = "Guardar Reporte de Insumos";
			saveDialog->FileName = "Reporte_Insumos_Almacen_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

				// 3. Escribir archivo
				StreamWriter^ writer = gcnew StreamWriter(saveDialog->FileName, false, System::Text::Encoding::UTF8);
				try {
					writer->WriteLine("============================================================");
					writer->WriteLine("              REPORTE DE INSUMOS POR ALMACÉN                ");
					writer->WriteLine("============================================================");
					writer->WriteLine("Fecha de Generación: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm:ss"));
					writer->WriteLine("Total Almacenes:     " + datos->Count);
					writer->WriteLine("------------------------------------------------------------");
					writer->WriteLine("");

					// Cabecera alineada
					writer->WriteLine(String::Format("{0,-30} | {1,15}", "ALMACÉN", "CANTIDAD INSUMOS"));
					writer->WriteLine("------------------------------------------------------------");

					// Filas
					int totalInsumos = 0;
					for each (ReporteInsumosXalmacen ^ item in datos) {
						writer->WriteLine(String::Format("{0,-30} | {1,15}", item->Nombre, item->CantInsumos));
						totalInsumos += item->CantInsumos;
					}

					writer->WriteLine("------------------------------------------------------------");
					writer->WriteLine(String::Format("{0,-30} | {1,15}", "TOTAL GENERAL", totalInsumos));
					writer->WriteLine("============================================================");
				}
				finally {
					writer->Close();
				}

				MessageBox::Show("Reporte exportado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al exportar: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	};
}