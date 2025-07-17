# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use KaitaiSbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Integrity;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Integrity::MsgSsrFlagSatellites;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{obs_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
    $self->{ssr_sol_id} = $self->{_io}->read_u1();
    $self->{chain_id} = $self->{_io}->read_u1();
    $self->{const_id} = $self->{_io}->read_u1();
    $self->{n_faulty_sats} = $self->{_io}->read_u1();
    $self->{faulty_sats} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{faulty_sats}}, $self->{_io}->read_u1();
    }
}

sub obs_time {
    my ($self) = @_;
    return $self->{obs_time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub ssr_sol_id {
    my ($self) = @_;
    return $self->{ssr_sol_id};
}

sub chain_id {
    my ($self) = @_;
    return $self->{chain_id};
}

sub const_id {
    my ($self) = @_;
    return $self->{const_id};
}

sub n_faulty_sats {
    my ($self) = @_;
    return $self->{n_faulty_sats};
}

sub faulty_sats {
    my ($self) = @_;
    return $self->{faulty_sats};
}

########################################################################
package Integrity::MsgSsrFlagIonoTileSatLos;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Integrity::IntegritySsrHeader->new($self->{_io}, $self, $self->{_root});
    $self->{n_faulty_los} = $self->{_io}->read_u1();
    $self->{faulty_los} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{faulty_los}}, Gnss::SvId->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub n_faulty_los {
    my ($self) = @_;
    return $self->{n_faulty_los};
}

sub faulty_los {
    my ($self) = @_;
    return $self->{faulty_los};
}

########################################################################
package Integrity::MsgSsrFlagIonoGridPointSatLos;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Integrity::IntegritySsrHeader->new($self->{_io}, $self, $self->{_root});
    $self->{grid_point_id} = $self->{_io}->read_u2le();
    $self->{n_faulty_los} = $self->{_io}->read_u1();
    $self->{faulty_los} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{faulty_los}}, Gnss::SvId->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub grid_point_id {
    my ($self) = @_;
    return $self->{grid_point_id};
}

sub n_faulty_los {
    my ($self) = @_;
    return $self->{n_faulty_los};
}

sub faulty_los {
    my ($self) = @_;
    return $self->{faulty_los};
}

########################################################################
package Integrity::IntegritySsrHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{obs_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{num_msgs} = $self->{_io}->read_u1();
    $self->{seq_num} = $self->{_io}->read_u1();
    $self->{ssr_sol_id} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{chain_id} = $self->{_io}->read_u1();
}

sub obs_time {
    my ($self) = @_;
    return $self->{obs_time};
}

sub num_msgs {
    my ($self) = @_;
    return $self->{num_msgs};
}

sub seq_num {
    my ($self) = @_;
    return $self->{seq_num};
}

sub ssr_sol_id {
    my ($self) = @_;
    return $self->{ssr_sol_id};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub chain_id {
    my ($self) = @_;
    return $self->{chain_id};
}

########################################################################
package Integrity::MsgAcknowledge;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{request_id} = $self->{_io}->read_u1();
    $self->{area_id} = $self->{_io}->read_u4le();
    $self->{response_code} = $self->{_io}->read_u1();
    $self->{correction_mask_on_demand} = $self->{_io}->read_u2le();
    $self->{correction_mask_stream} = $self->{_io}->read_u2le();
    $self->{solution_id} = $self->{_io}->read_u1();
}

sub request_id {
    my ($self) = @_;
    return $self->{request_id};
}

sub area_id {
    my ($self) = @_;
    return $self->{area_id};
}

sub response_code {
    my ($self) = @_;
    return $self->{response_code};
}

sub correction_mask_on_demand {
    my ($self) = @_;
    return $self->{correction_mask_on_demand};
}

sub correction_mask_stream {
    my ($self) = @_;
    return $self->{correction_mask_stream};
}

sub solution_id {
    my ($self) = @_;
    return $self->{solution_id};
}

########################################################################
package Integrity::MsgSsrFlagIonoGridPoints;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Integrity::IntegritySsrHeader->new($self->{_io}, $self, $self->{_root});
    $self->{n_faulty_points} = $self->{_io}->read_u1();
    $self->{faulty_points} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{faulty_points}}, $self->{_io}->read_u2le();
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub n_faulty_points {
    my ($self) = @_;
    return $self->{n_faulty_points};
}

sub faulty_points {
    my ($self) = @_;
    return $self->{faulty_points};
}

########################################################################
package Integrity::MsgSsrFlagTropoGridPoints;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Integrity::IntegritySsrHeader->new($self->{_io}, $self, $self->{_root});
    $self->{n_faulty_points} = $self->{_io}->read_u1();
    $self->{faulty_points} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{faulty_points}}, $self->{_io}->read_u2le();
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub n_faulty_points {
    my ($self) = @_;
    return $self->{n_faulty_points};
}

sub faulty_points {
    my ($self) = @_;
    return $self->{faulty_points};
}

########################################################################
package Integrity::MsgSsrFlagHighLevelDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{obs_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{corr_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_sol_id} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{chain_id} = $self->{_io}->read_u1();
    $self->{use_gps_sat} = $self->{_io}->read_u1();
    $self->{use_gal_sat} = $self->{_io}->read_u1();
    $self->{use_bds_sat} = $self->{_io}->read_u1();
    $self->{use_qzss_sat} = $self->{_io}->read_u1();
    $self->{reserved} = [];
    my $n_reserved = 5;
    for (my $i = 0; $i < $n_reserved; $i++) {
        push @{$self->{reserved}}, $self->{_io}->read_u1();
    }
    $self->{use_tropo_grid_points} = $self->{_io}->read_u1();
    $self->{use_iono_grid_points} = $self->{_io}->read_u1();
    $self->{use_iono_tile_sat_los} = $self->{_io}->read_u1();
    $self->{use_iono_grid_point_sat_los} = $self->{_io}->read_u1();
}

sub obs_time {
    my ($self) = @_;
    return $self->{obs_time};
}

sub corr_time {
    my ($self) = @_;
    return $self->{corr_time};
}

sub ssr_sol_id {
    my ($self) = @_;
    return $self->{ssr_sol_id};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub chain_id {
    my ($self) = @_;
    return $self->{chain_id};
}

sub use_gps_sat {
    my ($self) = @_;
    return $self->{use_gps_sat};
}

sub use_gal_sat {
    my ($self) = @_;
    return $self->{use_gal_sat};
}

sub use_bds_sat {
    my ($self) = @_;
    return $self->{use_bds_sat};
}

sub use_qzss_sat {
    my ($self) = @_;
    return $self->{use_qzss_sat};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

sub use_tropo_grid_points {
    my ($self) = @_;
    return $self->{use_tropo_grid_points};
}

sub use_iono_grid_points {
    my ($self) = @_;
    return $self->{use_iono_grid_points};
}

sub use_iono_tile_sat_los {
    my ($self) = @_;
    return $self->{use_iono_tile_sat_los};
}

sub use_iono_grid_point_sat_los {
    my ($self) = @_;
    return $self->{use_iono_grid_point_sat_los};
}

########################################################################
package Integrity::MsgSsrFlagHighLevel;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{obs_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iono_corr_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sat_corr_time} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ssr_sol_id} = $self->{_io}->read_u1();
    $self->{tile_set_id} = $self->{_io}->read_u2le();
    $self->{tile_id} = $self->{_io}->read_u2le();
    $self->{chain_id} = $self->{_io}->read_u1();
    $self->{use_gps_sat} = $self->{_io}->read_u1();
    $self->{use_gal_sat} = $self->{_io}->read_u1();
    $self->{use_bds_sat} = $self->{_io}->read_u1();
    $self->{use_qzss_sat} = $self->{_io}->read_u1();
    $self->{reserved} = [];
    my $n_reserved = 5;
    for (my $i = 0; $i < $n_reserved; $i++) {
        push @{$self->{reserved}}, $self->{_io}->read_u1();
    }
    $self->{use_tropo_grid_points} = $self->{_io}->read_u1();
    $self->{use_iono_grid_points} = $self->{_io}->read_u1();
    $self->{use_iono_tile_sat_los} = $self->{_io}->read_u1();
    $self->{use_iono_grid_point_sat_los} = $self->{_io}->read_u1();
}

sub obs_time {
    my ($self) = @_;
    return $self->{obs_time};
}

sub iono_corr_time {
    my ($self) = @_;
    return $self->{iono_corr_time};
}

sub sat_corr_time {
    my ($self) = @_;
    return $self->{sat_corr_time};
}

sub ssr_sol_id {
    my ($self) = @_;
    return $self->{ssr_sol_id};
}

sub tile_set_id {
    my ($self) = @_;
    return $self->{tile_set_id};
}

sub tile_id {
    my ($self) = @_;
    return $self->{tile_id};
}

sub chain_id {
    my ($self) = @_;
    return $self->{chain_id};
}

sub use_gps_sat {
    my ($self) = @_;
    return $self->{use_gps_sat};
}

sub use_gal_sat {
    my ($self) = @_;
    return $self->{use_gal_sat};
}

sub use_bds_sat {
    my ($self) = @_;
    return $self->{use_bds_sat};
}

sub use_qzss_sat {
    my ($self) = @_;
    return $self->{use_qzss_sat};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

sub use_tropo_grid_points {
    my ($self) = @_;
    return $self->{use_tropo_grid_points};
}

sub use_iono_grid_points {
    my ($self) = @_;
    return $self->{use_iono_grid_points};
}

sub use_iono_tile_sat_los {
    my ($self) = @_;
    return $self->{use_iono_tile_sat_los};
}

sub use_iono_grid_point_sat_los {
    my ($self) = @_;
    return $self->{use_iono_grid_point_sat_los};
}

1;
