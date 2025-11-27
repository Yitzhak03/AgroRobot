#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace AgroRobotController;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace AgroRobotModel;

	public ref class frmReporteInsumosXalmacen : public System::Windows::Forms::Form {
	public:
		frmReporteInsumosXalmacen(void)
		{
			InitializeComponent();
			// APLICAR EL NUEVO ESTILO CON AJUSTE DE POSICIONES
			AplicarEstiloProfesional();
		}

	protected:
		~frmReporteInsumosXalmacen()
		{
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnExportar;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnExportar = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();

			// chart1
			this->chart1->BackColor = System::Drawing::Color::White;
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(33, 98);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(679, 393);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";

			// label1
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Insumos por almacén";

			// label2
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(258, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Conteo de insumos registrados en cada almacén";

			// btnExportar
			this->btnExportar->Location = System::Drawing::Point(532, 37);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(180, 35);
			this->btnExportar->TabIndex = 3;
			this->btnExportar->Text = L"Exportar Reporte";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &frmReporteInsumosXalmacen::btnExportar_Click);

			// frmReporteInsumosXalmacen
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 529);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
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
		ReporteInsumosXalmacenController^ reporteCtrl = gcnew ReporteInsumosXalmacenController();
		List<ReporteInsumosXalmacen^>^ reporte = reporteCtrl->generarReporte();

		this->chart1->Series["Series1"]->Points->Clear();
		this->chart1->Series["Series1"]->ChartType = SeriesChartType::Column;
		this->chart1->Series["Series1"]->Color = System::Drawing::Color::FromArgb(118, 222, 146);
		this->chart1->Series["Series1"]->IsValueShownAsLabel = true;
		this->chart1->Series["Series1"]->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);

		for each (ReporteInsumosXalmacen ^ item in reporte) {
			this->chart1->Series["Series1"]->Points->AddXY(item->Nombre, item->CantInsumos);
		}
	}

	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			ReporteInsumosXalmacenController^ reporteCtrl = gcnew ReporteInsumosXalmacenController();
			List<ReporteInsumosXalmacen^>^ datos = reporteCtrl->generarReporte();

			if (datos->Count == 0) {
				MessageBox::Show("No hay datos para exportar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Reporte de Texto|*.txt";
			saveDialog->FileName = "Reporte_Insumos_Almacen_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				StreamWriter^ writer = gcnew StreamWriter(saveDialog->FileName, false, System::Text::Encoding::UTF8);
				writer->WriteLine("AGROROBOT - REPORTE DE INSUMOS");
				writer->WriteLine("Fecha: " + DateTime::Now.ToString("g"));
				writer->WriteLine("------------------------------------------------------------");
				writer->WriteLine(String::Format("{0,-30} | {1,15}", "ALMACÉN", "CANTIDAD"));
				writer->WriteLine("------------------------------------------------------------");
				int total = 0;
				for each (ReporteInsumosXalmacen ^ item in datos) {
					writer->WriteLine(String::Format("{0,-30} | {1,15}", item->Nombre, item->CantInsumos));
					total += item->CantInsumos;
				}
				writer->WriteLine("------------------------------------------------------------");
				writer->WriteLine("TOTAL: " + total);
				writer->Close();
				MessageBox::Show("Reporte exportado correctamente.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}

		   // =========================================================
		   //  ESTILO PROFESIONAL (CORREGIDO POSICIONES)
		   // =========================================================
	private: void AplicarEstiloProfesional() {
		// ===================================================================================
		// 1. PALETA DE COLORES "AGROROBOT"
		// ===================================================================================
		System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(246, 251, 248); // Menta Pálido
		System::Drawing::Color colorBoton = System::Drawing::Color::FromArgb(46, 143, 77);   // Verde Bosque
		System::Drawing::Color colorTextoMain = System::Drawing::Color::FromArgb(22, 53, 45); // Verde Petróleo (Títulos)
		System::Drawing::Color colorTextoSec = System::Drawing::Color::FromArgb(64, 106, 90);  // Verde Azulado (Subtítulos/Ejes)
		System::Drawing::Color colorGridLine = System::Drawing::Color::FromArgb(183, 220, 200); // Verde Agua (Líneas suaves)

		// ===================================================================================
		// 2. FUENTES
		// ===================================================================================
		// Título Principal (Coincide con frmMantInsumo)
		System::Drawing::Font^ fuenteTitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 17, FontStyle::Bold);
		// Subtítulo
		System::Drawing::Font^ fuenteSubtitulo = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Regular);
		// Botón
		System::Drawing::Font^ fuenteBoton = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Bold);
		// Textos del Gráfico (Ejes)
		System::Drawing::Font^ fuenteChartAxis = gcnew System::Drawing::Font("Segoe UI Semibold", 9);
		// Títulos de Ejes del Gráfico
		System::Drawing::Font^ fuenteChartTitle = gcnew System::Drawing::Font("Microsoft Tai Le", 10, FontStyle::Bold);

		// ===================================================================================
		// 3. CONFIGURACIÓN VENTANA
		// ===================================================================================
		this->BackColor = colorFondo;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		this->AutoSize = false;
		this->Dock = DockStyle::Fill;

		// ===================================================================================
		// 4. ALINEACIÓN DE TEXTOS Y BOTONES
		// ===================================================================================

		// Título Principal
		this->label1->Top = 20;
		this->label1->Left = 28;
		this->label1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
		this->label1->ForeColor = colorTextoMain; // Verde oscuro
		this->label1->Font = fuenteTitulo;
		this->label1->Text = "Insumos por Almacén";

		// Subtítulo (Detalle o descripción)
		this->label2->Top = 55; // Ajustado para quedar justo debajo del título
		this->label2->Left = 30;
		this->label2->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);
		this->label2->ForeColor = colorTextoSec; // Verde azulado suave
		this->label2->Font = fuenteSubtitulo;

		// Botón Exportar
		this->btnExportar->Top = 20; // Alineado visualmente con el título
		this->btnExportar->Size = System::Drawing::Size(160, 40); // Tamaño un poco más compacto
		this->btnExportar->Left = this->ClientSize.Width - this->btnExportar->Width - 30;
		this->btnExportar->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right);

		this->btnExportar->BackColor = colorBoton; // Verde Bosque
		this->btnExportar->ForeColor = System::Drawing::Color::White;
		this->btnExportar->FlatStyle = FlatStyle::Flat;
		this->btnExportar->FlatAppearance->BorderSize = 0;
		this->btnExportar->Font = fuenteBoton;
		this->btnExportar->Cursor = Cursors::Hand;

		// ===================================================================================
		// 5. ESTILIZACIÓN DEL GRÁFICO (CHART)
		// ===================================================================================
		int margen = 30;
		this->chart1->Top = 100;
		this->chart1->Left = margen;
		this->chart1->Width = this->ClientSize.Width - (margen * 2);
		this->chart1->Height = this->ClientSize.Height - this->chart1->Top - margen;

		this->chart1->Anchor = static_cast<AnchorStyles>(
			AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

		// El fondo externo del chart sigue el color del formulario
		this->chart1->BackColor = colorFondo;
		this->chart1->BorderlineColor = System::Drawing::Color::Empty;

		if (this->chart1->ChartAreas->Count > 0) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ area = this->chart1->ChartAreas[0];

			// El área de dibujo (plot) en blanco para resaltar los datos (igual que la Grilla)
			area->BackColor = System::Drawing::Color::White;

			// Sombras suaves o bordes
			area->BorderColor = colorGridLine;
			area->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			area->BorderWidth = 1;

			// Ejes X e Y (Líneas principales)
			area->AxisX->LineColor = colorTextoSec;
			area->AxisY->LineColor = colorTextoSec;

			// Líneas de la cuadrícula (Grid) - Usamos el "Verde Agua" suave
			area->AxisX->MajorGrid->LineColor = colorGridLine;
			area->AxisY->MajorGrid->LineColor = colorGridLine;
			area->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot; // Punteado para sutileza
			area->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;

			// Etiquetas de los ejes (Números/Nombres)
			area->AxisX->LabelStyle->Font = fuenteChartAxis;
			area->AxisY->LabelStyle->Font = fuenteChartAxis;
			area->AxisX->LabelStyle->ForeColor = colorTextoSec;
			area->AxisY->LabelStyle->ForeColor = colorTextoSec;

			// Títulos de los ejes
			area->AxisX->Title = "Almacén";
			area->AxisX->TitleFont = fuenteChartTitle;
			area->AxisX->TitleForeColor = colorTextoMain;

			area->AxisY->Title = "Cantidad";
			area->AxisY->TitleFont = fuenteChartTitle;
			area->AxisY->TitleForeColor = colorTextoMain;
		}

		// Leyenda (Opcional, desactivada según tu código original)
		if (this->chart1->Legends->Count > 0) {
			this->chart1->Legends[0]->Enabled = false;
		}
	}
	};
}