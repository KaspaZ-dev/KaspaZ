package=librustzcash
$(package)_version=0.1
$(package)_download_path=https://github.com/zcash/$(package)/archive/
$(package)_file_name=$(package)-$($(package)_git_commit).tar.gz
$(package)_download_file=$($(package)_git_commit).tar.gz
$(package)_sha256_hash=9909ec59fa7a411c2071d6237b3363a0bc6e5e42358505cf64b7da0f58a7ff5a
$(package)_git_commit=06da3b9ac8f278e5d4ae13088cf0a4c03d2c13f5
$(package)_dependencies=rust $(rust_crates)
$(package)_patches=cargo.config 0001-Start-using-cargo-clippy-for-CI.patch remove-dev-dependencies.diff

$(package)_rust_target=$(if $(rust_rust_target_$(canonical_host)),$(rust_rust_target_$(canonical_host)),$(canonical_host))
$(package)_library_file=target/release/librustzcash.a

define $(package)_set_vars
$(package)_build_opts=--frozen --release
$(package)_build_opts_mingw32=--target=x86_64-pc-windows-gnu
$(package)_build_opts_aarch64_linux=--target=aarch64-unknown-linux-gnu
$(package)_build_opts_x86_64_darwin=--target=x86_64-apple-darwin
$(package)_build_opts_aarch64_darwin=--target=aarch64-apple-darwin
endef

define $(package)_preprocess_cmds
  patch -p1 -d pairing < $($(package)_patch_dir)/0001-Start-using-cargo-clippy-for-CI.patch && \
  patch -p1 < $($(package)_patch_dir)/remove-dev-dependencies.diff && \
  mkdir .cargo && \
  cat $($(package)_patch_dir)/cargo.config | sed 's|CRATE_REGISTRY|$(host_prefix)/$(CRATE_REGISTRY)|' > .cargo/config
endef

# $(host_prefix)/native/bin/cargo build --package librustzcash $($(package)_build_opts)
define $(package)_build_cmds
  RUSTFLAGS="${RUSTFLAGS} -A unused_mut" cargo build --package librustzcash $($(package)_build_opts)
endef

define $(package)_stage_cmds
  [ -f target/$($(package)_rust_target)/release/librustzcash.a ] && \
    cp target/$($(package)_rust_target)/release/librustzcash.a $($(package)_library_file) || true && \
  mkdir -p $($(package)_staging_dir)$(host_prefix)/lib/ && \
  mkdir -p $($(package)_staging_dir)$(host_prefix)/include/ && \
  cp $($(package)_library_file) $($(package)_staging_dir)$(host_prefix)/lib/ && \
  cp librustzcash/include/librustzcash.h $($(package)_staging_dir)$(host_prefix)/include/
endef
